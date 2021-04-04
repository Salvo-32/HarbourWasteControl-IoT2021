# HarbourWasteControl IoT 2021 - Concept

HarbourWasteControl ai fini del controllo qualità delle acque portuali, prende in considerazione le esigenze dei due User personas principali coinvolti dalla problematica in oggetto:
1. Ente di gestione del porto 
2. Proprietari delle imbarcazioni, tramite sondaggi online ad un pool di proprietari reali  

## 1) Harbour managing authority's point of view
Il [Decreto Legislativo 24 giugno 2003, n. 182](https://www.camera.it/parlam/leggi/deleghe/03182dl.htm) è l'attuazione in Italia della [**direttiva europea** 2000/59/CE](https://eur-lex.europa.eu/legal-content/IT/TXT/?uri=celex:32000L0059), avente lo scopo (Art. 1 - Objectives) di ridurre gli scarichi illeciti in mare dei rifiuti reflui (acque dei servizi igienici, acque di lavaggio cisterne/stiva, also called Slop (Art. 2- Definitions)) prodotti dalle navi che utilizzano porti dello stato italiano. 
Secondo tale decreto qualsiasi tipo di nave, namely aliscafo, peschereccio, imbarcazione da diporto con finalità sportive/ricreative, sommergibili, tranne le navi militari, has to notificare al porto di scalo tramite apposito modulo (Art. 6 - Notifica), la necessità di conferire il proprio quantitativo stimato di acque reflue presso gli impianti portuali di raccolta, di cui ogni autorità portuale has to essere dotata per smaltire in sicurezza tali sostanze (Art. 4 - Impianti portuali di raccolta). Obviously, tale servizio garantito dall'ente gestore del porto prevede il pagamento delle tariffe per lo smaltimento (Art. 8 - Regime tariffario applicabile ai rifiuti prodotti dalla nave) a carico del comandante dell'imbarcazione. 

Unfortunately, nonstante le sanzioni previste (Art. 13 - Sanzione), i.e. sanzione amministrativa pecuniaria 3000€ - 30.000€ in caso di effrazione, nulla vieta al comandante della nave di notificare un quantitativo minore di materiale refluo da smaltire rispetto a quello reale, al fine di per raggirare la somma dovuta all'ente portuale per lo smaltimento. Il quantitivo non dichiarato può essere rilasciato secretly in porto prima della procedura ufficale di smaltimento.
In tale situazione, l'autorità portuale (defenceless) non possiede nussuna modalità concreta per rilevare la parziale effrazione con la conseguenza di inquinamneto delle acque portuali. Consequently, tale illecito rappresenta un pericolo reale per salute dei bagnanti presenti lungo le coste adiacenti al porto e un danno alla extraordinary beauty of EU's coastal areas ([Blue Growth - Coastal Tourism](https://ec.europa.eu/maritimeaffairs/policy/coastal_tourism)). 

Since questo deficit, HarbourWasteControl si propone come servizio per la rilevazione e gestione reale (See [Readme](/README.md), [Technology](/Technology.md)) delle above-mentioned offence a favore dello user-persona Ente gestore del porto 

## 2) Shipowner's point of view
Since/As/If, da un lato la prima entità interessata dalla gestione dello scarico illegale di acque reflue in porto è proprio the Harbour managing authority, dall'altro lato il cluster of people protagonista degli illeciti sono proprio gli shipowners. Therefore, another important user point of view is the one by the ownerships.
Per approfondire/studiare such problem dal punto di vista degli shipowner, si è preferito impiegare uno strumento diretto di indagine, quale un sondaggio somministrato tramite la piattaforma Google Forms a un pool di **real shipowners** ([Official link to the Poll](https://forms.gle/8TZQKGpQ1RFh6UQP9)). Data la nazionalità Italiana degli attendees al sondaggio, esso è stato rilasciato in lingua italiana (Sviluppi futuri del progetto, vedono la traduzione dello stesso in English). 
L'obiettivo del sondaggio è verificare il livello di conoscenza delle procedure di smaltimento dei rifiuti reflui prodotti dalle imbarcazioni in approdo nelle aree portuali, da parte dei relativi comandanti. Successivamente viene proposto ai partecipanti di esprimere la propria opinione in merito all'introduzione nelle banchine portuali di un sistema di rilevamento tecnologico, atto a prevenire lo smaltimento illecito di sostanze reflue in porto

A snapshot of the poll results is the following, provided by Google:
![LastPoll](/Picture/ShipOwners-Poll.png)

Processing the data of the survey, it is possible to clearly infer that: 
* the 50% half of the partecipants know how to deal with its wastewater, but unfortunately less than the 30% of them notify the harbour managing authorithy about the real amount of sewerage;
* about the idea to employ a technological system along the harbour docks to protect port water and human beings' health, the 70% of them state the need of doing something to get the water cleaner and healtier. This means the ship skippers are aware of the reality, i.e. the poor water quality inside the harbour;
* Even though there exists the 10% of attendees should be annoyed about the introduction of the underlying concepts offered by services like HarbourWasteControl, the 90% of them are more prone to getting better water quality;
* Eventually, the shipowners should appreciate the change more and more whether the port managing authority should offer them, discounts with respect to the harbour fees

## Storyboard

![Storyboard](/Picture/Storyboard-Complete.png)


## Sources
- https://www.camera.it/parlam/leggi/deleghe/03182dl.htm
- https://eur-lex.europa.eu/legal-content/IT/TXT/?uri=celex:32000L0059
- https://en.wikipedia.org/wiki/MARPOL_73/78
- https://forms.gle/8TZQKGpQ1RFh6UQP9
- https://www.storyboardthat.com
