# HarbourWasteControl IoT 2021 - Evaluation
The aim of this document is to describe HarbourWasteControl's performance in term of the different paramenters listed below. 
These paramenters come from the recommendations provided during the [IoT 2021 course 10589747](http://ichatz.me/Site/InternetOfThings2021), in particular from:
* Lecture 9 - UI/UX for IoT - [Prof. Ioannis Chatzigiannakis](https://github.com/ichatz)
* Lecture 11 - Performance Evaluation for IoT - [Prof. Andrea Vitaletti](https://github.com/andreavitaletti).
* Lecture 13 - LoRa networks - [Prof. Ioannis Chatzigiannakis](https://github.com/ichatz)
* Lecture 20 - Privacy Preserving Computation - [Prof. Andrea Vitaletti](https://github.com/andreavitaletti)
 
The following evaluation concerns both the one perfomed during the development phase and the one undertaken at the end of the project. Furthermore the evaluation is conducted at two different places:
* (Locally) Real local node [ST B-L072Z-LRWAN1](https://www.st.com/en/evaluation-tools/b-l072z-lrwan1.html), which makes use of LoRa modules and Turbidity and pH sensors
* (Remotely) FIT IoT-LAB Testbed, which provide #25 [ST B-L072Z-LRWAN1](https://www.iot-lab.info/docs/boards/st-b-l072z-lrwan1/), to perform large-scale evaluations

The evaluation of each paramenter includes:
* Explanation of the evaluation methodology, 
* List of the key performance indicators 
* Indication of the tool used to analyse the specified indicators
* Results

## Index
1. [User eXperience and satisfaction](#User-eXperience-and-satisfaction)
2. [Power consumption](#Power-consumption)
3. [Network technology assessment/Network performace](#Network-technology-assessment)
4. [Security and Privacy](#Security-and-Privacy)

## User eXperience and satisfaction 
As Don Norman and Jakob Nielsen state:
> User-experience encompasses all the aspects of the end-user's interaction with the company, its services and its products.

### Evaluation methodology
Since the end-user is the key element for the project it is important to analyse the user satisfaction degree during the project development. In order to this, the survey in [Concept.md](/Concept.md#2-shipowners-point-of-view) is involved.
 
The aim of the survey is to test the ship commanders’ level of knowledge of wastewater draining procedures. Afterwards participants are asked to express their opinion about the introduction of a technological system for water quality measurement to prevent the illegal draining of waste substances in the docks. For further details, i.e. actual outcomes, please refer to [Concept.md](/Concept.md#2-shipowners-point-of-view)

### Perfomance indicators
Indicator name | Description
------------ | -------------
Desired characteristics | Lst of potential functionalities that shipowner would like to add
Interest of pullution data produced by HWC | four different levels of ascending interest
Way of communication | list of possible media to receive HWC information 

### Tool
The above survey makes use of Google Forms platform that is a survey administration software included as part of the free, web-based Google Docs Editors suite offered by Google. The app allows users to create and edit surveys online while collaborating with other users in real-time (More details at [Google Forms](https://www.google.com/intl/en-GB/forms/about/)).
It is carried out in Italian as the people involved in the survey are Italian (Future developments of the project see it translated into English). 

### Results
A snapshot of the poll results is the following, provided by Google:
![LastPoll](/Picture/ShipOwners-Poll.png)

Processing the data of the survey, it is possible to clearly infer that: 
1. 50% of the partecipants know how to deal with their wastewater, but unfortunately less than 30% of them notify the harbour managing authorithy of the real amount of sewerage;
2. As concern the idea of employing a technological system along the harbour docks to protect port waters and human beings' health, 70% of them state the need to do something to get the water cleaner and healthier. This means that ship skippers are aware of the reality, i.e. the poor quality of harbour waters;
3. Even though 10% of attendees are annoyed by the introduction of inspection services like HarbourWasteControl, 90% of them are proner to getting better water quality;
4. Eventually, the shipowners would appreciate this service more whether the port managing authority offered them discounts with respect to the harbour fees

## Power consumption
This assesment analyses energy consumption of both real node and remote nodes, by measuring current and power levels during [firmware](Demo/main.c) is running on
### Evaluation methodology
Current and power consumption of the real node is measured through the digital multimeter [Mastech MS8217](https://www.hackster.io/digilent/products/mastech-ms8217-autorange-digital-multimeter).


The feature offered by iot-lab.info is used to monitor the voltage, current and power consumption of the IoT system. 


### Perfomance indicators
* Current [mA]
* Power [mW]

### Tool
* Digital multimeter [Mastech MS8217](https://www.hackster.io/digilent/products/mastech-ms8217-autorange-digital-multimeter)
* [INA226](https://www.ti.com/product/INA226) by Texas Instruments is a current shunt and power monitor with an I2C or SMBUS-compatible interface. The device monitors both a shunt voltage drop and bus supply voltage. It enables direct readouts of **current** in amperes and **power** in watts


### Results

## Network technology assessment
### Network traffic analysis

## Security and Privacy 
Use the security protocol offered by LoRaWAN 1.0 that specifies the use of a number of security keys: NwkSKey, AppSKey and AppKey. All keys have a length of 128 bits, the algorithm used is AES-128. Before a node can exchange messages in the LoRaWAN network, activation procedure has to be finished. For the project we use Over-the-Air Activation (OTAA) method.

## Sources
* https://www.google.com/intl/en-GB/forms/about/
* https://en.wikipedia.org/wiki/Google_Forms
