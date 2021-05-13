## Comments received during first delivery
* Instead of just reading the values from the sensors and analyze wheter the dock is polluted or not, it would be better to perform an overall analysis on the port water, namely estimate the values (pH, turbidity, ...)  on a region of the port water
* Remove use floating anti-pollution barrier, becuase they are only used only if a boat is know is releasing polluted substances. To surround each mooring boat with  a barrier is practically impossible.
* Simplify storyboards, using less pictures
* Sensors are not suitable for the goal in a real world scenario
* Cost of the single components in this phase is not important
## Changes made from the first delivery
### Concept
* Changed storyboad, focusing only on polluted harbor
### Technology
* Change sources, included [D. Lgs 152/06](https://www.gazzettaufficiale.it/atto/serie_generale/caricaArticolo?art.progressivo=0&art.idArticolo=5&art.versione=1&art.codiceRedazionale=006G0171&art.dataPubblicazioneGazzetta=2006-04-14&art.idGruppo=54&art.idSottoArticolo1=10&art.idSottoArticolo=1&art.flagTipoArticolo=2). This decree regulates all the parameters (TSS, pH, temperature) to be analyzed on superficial waters, stating the limits of the values read.
* Removed MQTT-S portocol since we are using lora
* Added draft about machine learning method to estimate the values on a region of the port water
### Evaluation
* Add draft about Security and Privacy section
* Removed Cost section
## Missing functionalities
* Finalize machine learning method on Technology part
* Complete Security and Privacy section
* Monitor and analyze power consmption using IoTLab
* Monitor and analyze the network traffic performances using IoTLab
