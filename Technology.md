# HarbourWasteControl IoT 2021 - Technology
## Architecture
For each boat a sensor node is deployed, with a unique id that identifies the area the boat is moored. Each area is associated with a gateway that receives the data from the node and then send it to the cloud. The cloud-based backend analyzes the data and make it possible to the user to view the analysis and the data collected.
## Networking
The sensor node and the gateway comunicate via MQTT over LoRa. Each sensor node publishes only on one topic associated with its own unique identifier. The gateway act as both MQTT-SN broker and MQTT broker, and also as tranparent bridge between the two. The gateway once it receives data from one node it sends it to the cloud-based backend via 3G/4G.
## Components
The sensor node is composed of a microcontroller, one pH sensor, one Torbidity sensor and a LoRa module.
RIOT OS is used to make it as easy as possible the coding of network functionalities and sensor drivers.
The gateway is a linux system running RSMB (Really Small Message Broker) and Mosquitto.

Sources
1. https://www.researchgate.net/publication/7869606_Statistical_analyses_of_coastal_water_quality_for_a_port_and_harbor_region_in_India
2. https://www.eea.europa.eu/publications/european-bathing-water-quality-in-2019/european-bathing-water-quality-in-2019
