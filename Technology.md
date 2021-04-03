# HarbourWasteControl IoT 2021 - Technology
## Architecture
For each boat a sensor node is deployed, with a unique id that identifies the area the boat is moored. Each area is associated with a gateway that receives the data from the node and then send it to the cloud. For the cloud-based backend services, we use AWS. AWS analyzes the data and make it possible to the user to view the analysis and the data collected.

## Networking
The sensor node and the gateway comunicate via MQTT over LoRa. Each sensor node publishes only on one topic associated with its own unique identifier. The gateway act as both MQTT-SN broker and MQTT broker, and also as tranparent bridge between the two. The gateway once it receives data from one node it sends it to the cloud-based backend via 3G/4G.

## Components
The sensor node is composed of a Nucleo-f401re board, one pH sensor, one Turbidity sensor SKU SEN0189 and a LoRa module.
- The Nucleo-f401re board is a 32-bit ARM based microcontroller. The board will run RIOT OS used to make it as easy as possible the coding of network functionalities and sensor drivers.
- The Turbidity sensor SKU SEN0189 detects the water quality useing light to detect suspended particles in water by measuring the light transmittance and scattering rate, which changes with the amount of total suspended solids (TSS) in water. 
- The pH sensor integrates the LM35 temperature sensor, where a probe must be attached to the BNC connector and the board must be connected using PH2.0 port.

The gateway conists of a raspberry pi with a Dragino LoRa shield attached. 
- The rasppberry will run linux and executes RSMB (Really Small Message Broker), the MQTT-SN borker, and Mosquitto, the MQTT broker.

Sources
1. https://wiki.dfrobot.com/Turbidity_sensor_SKU__SEN0189
2. https://www.futurashop.it/modulo-per-sensore-ph-8300-YB427
3. https://www.futurashop.it/sensore-ph-2846-PHSENSOR
4. https://www.researchgate.net/publication/7869606_Statistical_analyses_of_coastal_water_quality_for_a_port_and_harbor_region_in_India
5. https://www.eea.europa.eu/publications/european-bathing-water-quality-in-2019/european-bathing-water-quality-in-2019
