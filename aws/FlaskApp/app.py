import random
import numpy as np
import pyKriging  
from pyKriging.krige import kriging  
from flask import Flask
from flask import render_template
import boto3
from boto3.dynamodb.conditions import Key

app = Flask(__name__)

device_ids = ["dwkm2wm0dev1","dwkm2wm0dev2","dwkm2wm0dev3","dwkm2wm0dev4"]

def predict_values(krigingobj, plotgrid=61):
	
	# Generates x and y coordinates	
	X = np.linspace(krigingobj.normRange[0][0],
		krigingobj.normRange[0][1], num=plotgrid)
	Y = np.linspace(krigingobj.normRange[1][0],
		krigingobj.normRange[1][1], num=plotgrid)

	# Predicted values
	zs = np.array([krigingobj.predict([x,y]) for x,y in zip(np.ravel(X), np.ravel(Y))])	
	Z = zs.reshape(X.shape)

	# Calculate errors between original and predicted
	zse = np.array([krigingobj.predict_var([x,y]) for x,y in zip(np.ravel(X), np.ravel(Y))])
	Ze = zse.reshape(X.shape)
	
	return X,Y,Z,Ze

def query_devices(device_ids, dynamodb=None):	

	if not dynamodb:
		dynamodb = boto3.resource('dynamodb')

	location = []
	ph = []
	turbidity = []

	for device_id in device_ids:

		table = dynamodb.Table('HarbourWasteControl')
		response = table.query(
			KeyConditionExpression=Key('deviceId').eq(device_id),
			ScanIndexForward=False,	 # get first values with higher timestamp
			Limit=1
		)
		
		if response['Items'] != []:
			item = response['Items'][0]
			location.append( [float(item['latitude']), float(item['longitude'])] )
			ph.append(float(item['ph']))
			turbidity.append(float(item['turbidity']))	

	return location, ph, turbidity
 

@app.route("/",methods=["GET"])
def homepage():
	return render_template("index.html")

@app.route("/getdata",methods=["GET"])
def get_data():
	
	print('Fetch sensor data from database: ..')		
	location_sensors, ph_values, turbidity_values = query_devices(device_ids)
	
	turbidity_values = np.array(turbidity_values)
	ph_values = np.array(ph_values)	
	location_sensors = np.array(location_sensors)

	position_sensors_x = location_sensors[:,0]
	position_sensors_y = location_sensors[:,1]

	optimizer = 'ga'

	print('Kriging training ..')
	
	krigingobj_tur = kriging(location_sensors, turbidity_values)
	krigingobj_tur.train(optimizer = optimizer)

	krigingobj_ph = kriging(location_sensors, ph_values)
	krigingobj_ph.train(optimizer = optimizer)

	print('Predict values ..')
		
	phX, phY, phZ, phZe = predict_values(krigingobj_ph)
	turX, turY, turZ, turZe = predict_values(krigingobj_tur)
	
	return {
		"positionSensorsX": position_sensors_x.tolist(),
		"positionSensorsY": position_sensors_y.tolist(),
		"ph": {
			"X": phX.tolist(),
			"Y": phY.tolist(),
			"Z": phZ.tolist(),
			"Ze": phZe.tolist(),
			},
		"turbidity": {
			"X": turX.tolist(),
			"Y": turY.tolist(),
			"Z": turZ.tolist(),
			"Ze": turZe.tolist()
		}
	}

