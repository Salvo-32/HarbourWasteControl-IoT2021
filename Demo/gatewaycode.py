import time
import json
import paho.mqtt.client as mqtt 
import numpy
import random
import pyKriging  
from pyKriging.krige import kriging  
import base64

X=[]
y=[]

def on_message(client, userdata, message):
    print("received message\n")
    payload = json.loads(message.payload)['payload_raw']
    payload = base64.b64decode(payload).decode("utf-8")
    payload = payload.split('\n')
    X.append([float(payload[0]), float(payload[1])])
    y.append(float(payload[2]))

mqttBroker ="eu.thethings.network"

client = mqtt.Client()
client.username_pw_set('dwkm2wm0','ttn-account-v2.yaF_Jq02uaW8OgN9hGO1tEEI2_MVx3KDuC03D9e0ryA')
client.connect(mqttBroker) 

client.loop_start()

client.subscribe('+/devices/+/up')
client.on_message=on_message 

time.sleep(120)
client.loop_stop()

print(X)
print(y)

X=numpy.array(X)
y=numpy.array(y)

optimizer = 'ga'

k = kriging(X, y)
k.train(optimizer = optimizer)

k.plot()

