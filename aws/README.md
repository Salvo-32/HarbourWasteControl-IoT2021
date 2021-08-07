This directory contains the code that will run in AWS.

In lambda there is the code executed by the AWS Lambda service.
	* storeIntoDB-HarbourWasteControl.js read the messages sent from IoT core, decode the payload encoded in base64 and then store them in a dyanamodb table

FlaskApp contains :
	* the code that performs the Gaussian process regression (Kriging) on the data retrieved from dynamodb
	* the dashboard that has the goal of retrieve the results from the analysis of the data and display the data to the user 
