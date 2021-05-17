# 2nd delivery
## Comments received during first delivery
* Instead of just reading the values from the sensors and analyze wheter the dock is polluted or not, it would be better to perform an overall analysis on the port water, namely estimate the values (pH, turbidity, ...)  on a region of the port water
* Remove use floating anti-pollution barrier, becuase surrounding each mooring boat with a barrier is practically impossible in a real world scenario. It could be helpuful at most to surround a suspected boat that is releasing polluted substances.
* Simplify storyboards, using less pictures. More focus on a specific scenario
* Sensors are not suitable for the goal in a real world scenario
* Cost of the single components in this phase is not important
## Changes since the first delivery
### Concept
* Changed storyboad, focusing only on polluted harbor
### Technology
* Change sources to **support and legitimize** validity of the specified sensors of the first group assignment, namely we make use of the legislative decree [D. Lgs 152/06](https://www.gazzettaufficiale.it/atto/serie_generale/caricaArticolo?art.progressivo=0&art.idArticolo=5&art.versione=1&art.codiceRedazionale=006G0171&art.dataPubblicazioneGazzetta=2006-04-14&art.idGruppo=54&art.idSottoArticolo1=10&art.idSottoArticolo=1&art.flagTipoArticolo=2). This decree regulates all the parameters (TSS, pH, temperature) to be analyzed on superficial waters, stating the limits of the that values.
* Removed MQTT-S portocol since we are using LoRa technology
* Added draft about machine learning algorithm to estimate the above-mentioned values on a point of the port water not covered by sensors (Spatial Interpolation Model)
### Evaluation
* Add draft about Security and Privacy section
* Removed Cost section since it is out of the scope of this course
## Missing functionalities
* Finalize machine learning algorithm on Technology part
* Complete Security and Privacy section
* Monitor and analyze power consmption using IoTLab
* Monitor and analyze the network traffic performances using IoTLab
