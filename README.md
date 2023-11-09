# 2023_1D_S5_SystNum_Korchef_Diler

TP1  systèmes numériques

Le MCP23S17 est un composant permettant d’étendre le nombre d’entrées/sorties de la carte STM32.
Il permet de gérer 8 GPIO simultanément. Dans notre application, ces GPIOs seront configurés en Input.
Il est possible de communiquer avec le composant à une fréquence de 10 Mhz.

Les broches connectées au microcontrolleur sont les suivantes : 
- SCK, c’est l’entrée de l’horloge

- A0, A1 et A2 permettent de communiquer des adresses hardware

- INTB et INTA permettent de faire des interruptions

- NC/CS permet de savoir quel carte est utilisée entre la MCP23S17 et la MCP23017

- VSS et VDD servent à l’alimentation

- SI et SO servent à communiquer des données

- RESET permet de reset le composant

Tableau des pins sur le microcontrolleur en fonction des pins sur le composant : 

A0

A1

A2

INTB

INTA

NC/CS

VSS

VDD

SI

SO

RESET

