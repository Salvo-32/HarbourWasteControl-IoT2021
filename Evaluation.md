# HarbourWasteControl IoT 2021 - Evaluation
The aim of this document is to describe HarbourWasteControl's performance in term of the different paramenters listed below. These paramenters come from the recommendations provided inside/during the [IoT 2021 course 10589747](http://ichatz.me/Site/InternetOfThings2021), in particular from Lectures 9, 15, 19, 20 by [Prof. Ioannis Chatzigiannakis](https://github.com/ichatz) and Lecture 11 by [Prof. Andrea Vitaletti](https://github.com/andreavitaletti). Furthermore, the following evaluation concern both the one perfomed during the development and the one undertaken at the of the project.     

The evaluation of a paramenter comprises:
* Explanation of the evaluation methodology, 
* List of the key performance indicators 
* Indication of the tool used to analyse the specified indicators   

## Index
1. [User eXperience and satisfaction](Evaluation.md/#User-eXperience-and-satisfaction)
2. [Power consumption](Evaluation.md/#Power-consumption)
3. [Network technology assessment](Evaluation.md/#Network-technology-assessment)
4. [Security and Privacy](Evaluation.md/#Security-and-Privacy)
5. [Cost](Evaluation.md/#Cost)

## User eXperience and satisfaction 
As Don Norman and Jakob Nielsen state:
> User-experience encompasses all the aspects of the end-user's interaction with the company, its services and its products.

### Evaluation methodology
Since the end-user is the key element for the project it is important to analyse the user satisfaction degree during the project development and when the first release of HarbourWasteControl will be available. In order to this, two different surveys ([Middle-term survey](/Evaluation#Middle-term-survery), [First-release survey](/Evaluation#First-release-survey)) will be carried out to a pool of real shipowners, the one already involved in [Concept](/Concept.md).
 
The aim of the survey is to test the ship commanders’ level of knowledge of wastewater draining procedures. Afterwards participants are asked to express their opinion about the introduction of a technological system for water quality measurement to prevent the illegal draining of waste substances in the docks.

### Perfomance indicators
Middle-term survey

Indicator name | Description
------------ | -------------
Desidered HarbourWasteControl characteristics | list of potential functionalities that shipowner would like to add
Interest of pullution data produced by HWC | four different levels of ascending interest
Way of communication | list of possible media to receive HWC information 

First-release survey
Indicator name | Description
------------ | -------------
Satisfaction of the preferred way of communication | four different levels of ascending satisfaction degree
Actual water quality improvement | Real effects of the project against illegal wastewater draining  
Further improvements | open textbox for shipowners' hint  

### Tool
Both the above surveys make use of Google Forms platform that is a survey administration software included as part of the free, web-based Google Docs Editors suite offered by Google. The app allows users to create and edit surveys online while collaborating with other users in real-time (More details at [Google Forms](https://www.google.com/intl/en-GB/forms/about/)).
They will be carried out in Italian as the people involved in the survey are Italian (Future developments of the project see it translated into English). 


#### Middle-term survery
TBA

#### First-release survey
TBA

## Power consumption
The feature offered by iot-lab.info is used to monitor the voltage, current and power consumption of the IoT system. 
The consumption of the real node is measured through an INA226 hardware component.

### Evaluation methodology


### Perfomance indicators
* Current [mA]
* Power [mW]

### Tool
* INA226 current/power monitor component
* Ammeter / Wattmeter

## Network technology assessment
### Network traffic analysis

## Security and Privacy 
TBA

## Cost
* Sensor node
  * Nucleo-f401re ~ 20€
  * pH sensor ~ 20€
  * Turbidity sensor ~ 20€
  * Lora shield ~ 30€
  * Portable battery ~ 20€
  * Waterproof case ~ 20€
* Gateway
  * Raspberry pi ~ 30€
  * Lora shield ~ 30€
  * Solar panel (optional) ~ 50 €
  * Portable battery (optional) ~ 30€
  * 3g/4g shield ~ 40€
  * Waterproof case ~ 20€

## Sources
* https://www.google.com/intl/en-GB/forms/about/
* https://en.wikipedia.org/wiki/Google_Forms
