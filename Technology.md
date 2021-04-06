# HarbourWasteControl IoT 2021 - Technology
## Architecture
For each boat a sensor node is deployed, with a unique id that identifies the area the boat is moored. Each area is associated with a gateway that receives the data from the node and then send it to the cloud. For the cloud-based backend services, we use AWS. AWS analyzes the data and make it possible to the user to view the analysis and the data collected.

Before the system can working properly it is necessary a calibration phase where the system can understand which are the "normal" values at the port. This allows the cloud analytics program to have an intial database to start its analysis.

## Networking
The sensor node and the gateway comunicate via MQTT over LoRa. Each sensor node publishes only on one topic associated with its own unique identifier. The gateway act as both MQTT-SN broker and MQTT broker, and also as tranparent bridge between the two. The gateway once it receives data from one node it sends it to the cloud-based backend via 3G/4G.

In case of a problem with the sensor node, for example a sensor mulfunction or battery exhausted, the sensor node will send a message on the same topic to the gateway with some information about the problem, that then will be sent to the cloud. In case of a problem with the gateway, in a similar way the gateway will send a message to the cloud in a special topic used only for this type of events.

Lora classify end nodes in three differnet classes. The sensor nodes are considered Class A, battery powered sensor with no latency constraint, while the gateway is class C, because it can listen all the time for data.

## Components
The sensor node is composed of a Nucleo-f401re board, one pH sensor, one Turbidity sensor SKU SEN0189 and a LoRa module.
- The Nucleo-f401re board is a 32-bit ARM based microcontroller. The board will run RIOT OS used to make it as easy as possible the coding of network functionalities and sensor drivers.
- The Turbidity sensor SKU SEN0189 measure the turbidity is the cloudiness or haziness of a fluid caused by large numbers of individual particles that are generally invisible to the naked eye, similar to smoke in air. The measurement of turbidity is a key test of water quality. The sensdor detects the water quality using light to detect suspended particles in water by measuring the light transmittance and scattering rate, which changes with the amount of total suspended solids (TSS) in water. The units of turbidity from a calibrated nephelometer are called Nephelometric Turbidity Units (NTU). Its power consume doesn't exceed 40mA.
- The pH sensor measure the pH, a scale used to specify the acidity or basicity of an aqueous solution. The pH of seawater is typically limited to a range between 7 and 8, and it plays an important role in the ocean's carbon cycle. The sensor works with a probe attached to the BNC connector, while the board must be connected using PH2.0 port. Its power consume doesn't exceed 10mA.

The sensor node components will be appropriately shielded by a waterproof enclousure to prevent damage by water, and in general by atmospheric phenomena.

The gateway conists of a raspberry pi with a Dragino LoRa shield attached. 
- The rasppberry will run linux and executes RSMB (Really Small Message Broker), the MQTT-SN borker, and Mosquitto, the MQTT broker.

![Image1](Picture/architecture.png?raw=true)
![Image1](Picture/architecture2.png?raw=true)

#### Sources
1. https://wiki.dfrobot.com/Turbidity_sensor_SKU__SEN0189
2. https://wiki.dfrobot.com/PH_meter_SKU__SEN0161_
3. https://www.eea.europa.eu/publications/european-bathing-water-quality-in-2019/european-bathing-water-quality-in-2019
4. https://sensorex.com/ph-sensors-3/#comb-ph-tab
5. https://en.wikipedia.org/wiki/PH#Seawater
6. https://en.wikipedia.org/wiki/Turbidity
