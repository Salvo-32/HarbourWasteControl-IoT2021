# HarbourWasteControl IoT 2021 - Concept

In order to inspect the quality of port waters, HarbourWasteControl takes into account the needs of two main user personas involved in the matter in hand
1. The harbour managing authority 
2. The shipowners through online surveys to a pool of real owners  

## 1. Harbour managing authority's point of view (Problem description)
The [Legislative decree of 24th JUNE 2003, N.182](https://www.camera.it/parlam/leggi/deleghe/03182dl.htm) is the fulfilment in Italy of the [**European directive 2000/59/CE**](https://eur-lex.europa.eu/legal-content/IT/TXT/?uri=celex:32000L0059) with the aim (Art.1 - Objectives) of reducing the illegal discharge of wastewater in the sea (toilet waters, tank/hold washing waters, also called Slop(Art.2 - Definitions)), produced by the ships in the Italian ports.

According to that decree, any kind of ship (hydrofoils, fishing boats, pleasure boats with sports/recreative aims, submarines), except military ships, has to notify port authority, using the proper form (Art.6 - Notification), the necessity of draining the estimated quantity of wastewater. All port authorities have to be equipped with port reception facilities in order to dispose of the waste in a safe way (Art.4). Obviously, the above mentioned service foresees the payment of rates  by the ship commander  (Art.8 - Tariff system applicable to the waste materials produced by the ship).

Unfortunately, in spite of the economic sanctions foreseen by the law (Art.13-Sanction), i.e.pecuniary administrative sanction 3000€ - 30000€ in case of offence,  it is common among ship commanders to notify a false amount of wastewater (obviously smaller than the real amount) to pay less money for the draining. The non-declared amount is usually secretly dismissed in the port before the official draining procedure. In a situation like this, the harbour authority has no concrete way to notice the partial offence that contributes to polluting the harbour waters. 

As a consequence, such an offence represents  real environmental danger and  damages to the extraordinary beauty of EU’s coastal areas ([Blue Growth - Coastal Tourism](https://ec.europa.eu/maritimeaffairs/policy/coastal_tourism)).
To avoid this, HarbourWasteControl proposes itself as a service for the detection and prediction (relying on [Kriging method](Technology.md#kriging-method)) of the water quality near the harbour in favour of the harbour managing authority

## 2. Shipowner's point of view
Whereas on one hand the Harbour managing authority is the first entity affected by the of the illegal draining of  wastewater, on the other hand the shipowners are the real protagonists of these offences. Therefore another important user’s point of view is that of the ownerships. 
To study such problem from their point of view, a direct survey tool has been used, that is a survey carried out to a pool of **real shipowners** via Google  Forms platform ([Official link to the Poll](https://forms.gle/8TZQKGpQ1RFh6UQP9)). The survey has been carried out in Italian as the people involved in the survey are Italian (Future developments of the project see it translated into English). 
The aim of the survey is to test the ship commanders’ level of knowledge of wastewater draining procedures. Afterwards participants are asked to express their opinion about the introduction of a technological system for water quality measurement to prevent the illegal draining of waste substances in the docks.

A snapshot of the poll results is the following, provided by Google:
![LastPoll](/Picture/ShipOwners-Poll.png)

Processing the data of the survey, it is possible to clearly infer that: 
1. 50% of the partecipants know how to deal with their wastewater, but unfortunately less than 30% of them notify the harbour managing authorithy of the real amount of sewerage;
2. As concern the idea of employing a technological system along the harbour docks to protect port waters and human beings' health, 70% of them state the need to do something to get the water cleaner and healthier. This means that ship skippers are aware of the reality, i.e. the poor quality of harbour waters;
3. Even though 10% of attendees are annoyed by the introduction of inspection services like HarbourWasteControl, 90% of them are proner to getting better water quality;
4. Eventually, the shipowners would appreciate this service more whether the port managing authority offered them discounts with respect to the harbour fees

## Storyboard

![Storyboard](/Picture/Storyboard-Complete.png)

## Previous versions of this document
* First version of the Concept file can be found [here](https://github.com/Salvo-32/HarbourWasteControl-IoT2021/blob/6a600ffb777f99500abf55af4701394b647948be/Concept.md)
* Second version of the Concept file can be found [here](https://github.com/Salvo-32/HarbourWasteControl-IoT2021/blob/fc6fac34cee5149cbdab9ec8186ca964ee297700/Concept.md)

## Sources
- https://www.camera.it/parlam/leggi/deleghe/03182dl.htm
- https://eur-lex.europa.eu/legal-content/IT/TXT/?uri=celex:32000L0059
- https://en.wikipedia.org/wiki/MARPOL_73/78
- https://forms.gle/8TZQKGpQ1RFh6UQP9
- https://www.storyboardthat.com
