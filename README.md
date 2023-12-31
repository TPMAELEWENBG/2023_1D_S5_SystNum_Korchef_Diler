# 2023_1D_S5_SystNum_Korchef_Diler

TP1  systèmes numériques

Le MCP23S17 est un composant permettant d’étendre le nombre d’entrées/sorties de la carte STM32.
Il permet de gérer 8 GPIO simultanément. Dans notre application, ces GPIOs seront configurés en Input.
Il est possible de communiquer avec le composant à une fréquence de 10 Mhz.

Les broches connectées au microcontrolleur sont les suivantes : 
- SCK, c’est l’entrée de l’horloge

- NC/CS permet de savoir quel carte est utilisée entre la MCP23S17 et la MCP23017

- VSS et VDD servent à l’alimentation

- SI et SO servent à communiquer des données

- RESET permet de reset le composant

Tableau des pins sur le microcontrolleur en fonction des pins sur le composant :

PINS COMPOSANT     |      PINS MICROCONTROLLEUR

SCK                       PC10

A0                        GND

A1                        GND

A2                        GND

NC/CS                     PB7

VSS                       GND

VDD                       3.3V

SI                        PB5

SO                        PC11

RESET                     PA0

A0, A1 et A2 permettent de communiquer des adresses hardware
Un opcode est l'instruction à réaliser par le microcontrolleur. Dans notre cas R/W, write = 0 et read = 1
INTB et INTA permettent de faire des interruptions
Pour allumer une LED, la valeur de sortie d'une pin doit etre de 0.6V.
Les résistances servent à limiter le courant dans les LEDs pour ne pas les endommager.
Leurs valeurs ne sont pas les mêmes car les LEDs sont différentes. 560 ohms pour les vertes et 680 pour les oranges et rouges.
IODIRA, IODIRB sont les registres qui codent la direction des GPIOs (input ou output)
GPIOA et GPIOB sont les états des GPIOs (0 ou 1)

Pour que toutes les LEDs soient allumées, les bits de GPIOA et GPIOB doivent tous être à 1, et IODIRA et IODIRB doivent être en output (donc 0).
Pour qu'elles soient toutes éteintes, les bits de GPIOA et B doivent être à 0.
Pour que seulement la LED D508 soit allumée, il faut que le dernier bit de GPIOB soit à 1, et que tous les autres soient à 0.

La séquence de valeurs à envoyer pour configurer les pins : 
Il faut write 0 sur les registres IODIRA et IODIRB.
Adresse de IODIRA : 00h
Adresse de IODIRB : 10h
donc on envoie pour mettre le registre IODIRA à 0 : 
opcode : 0x40, register adress : 0x00 data : 0x00
et on envoie tout à la suite 0x40 0x00 0x00

donc on envoie pour mettre le registre IODIRB à 0 : 
opcode : 0x40, register adress : 0x40, data : 0x00
On envoie une trame de 3 octets : 0x40 0x40 0x00


La séquence de valeurs à envoyer pour éteindre puis allumer toutes les LEDs:
Il faut write 0 sur tous les bits des registres GPIOA et GPIOB puis 1.
on envoie :
opcode : 0x40, register adress : 0x12, data : 0x00
donc on envoie la trame : 0x40 0x12 0x00 pour le registre A
puis 0x40 0x13 0x00 pour le registre B

ensuite on envoie 1 sur les registres : 
0x40 0x12 0xFF
0x40 0x13 0xFF

Configuration du microcontrolleur : 

![image](https://github.com/TPMAELEWENBG/2023_1D_S5_SystNum_Korchef_Diler/assets/150352059/059388e7-4c95-4293-a126-1a67ab4be771)

![image](https://github.com/TPMAELEWENBG/2023_1D_S5_SystNum_Korchef_Diler/assets/150352059/d652617c-44e1-4552-a5be-49fabee669ca)


