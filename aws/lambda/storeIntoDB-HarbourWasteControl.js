console.log('Loading function');
var AWS = require('aws-sdk');
var dynamo = new AWS.DynamoDB.DocumentClient();
var table = "HarbourWasteControl";

exports.handler = function(event, context) {
    console.log(event)
   
    var jsonstring = Buffer.from(event.payload, 'base64').toString('ascii');
    var payload = JSON.parse(jsonstring);
   
    var paramsDB = {
    TableName:table,
    Item:{
        "timestamp" : event.timestamp,
        "deviceId": event.deviceId,
        "latitude": payload.latitude,
        "longitude": payload.longitude,
        "ph" : payload.ph,
        "turbidity" : payload.turbidity
        }
    };
    
    console.log("Adding a new IoT device...");
    dynamo.put(paramsDB, function(err, data) {
        if (err) {
            console.log(err)
            context.fail();
        } else {
            console.log("Data inserted");
            context.succeed();
        }
    });
}
