# Rapport de Projet : microcontrôleur STM32L053

---

## I. Introduction

Dans le cadre de ce projet, nous avons développé un système permettant de contrôler une LED RGB à l'aide d'un microcontrôleur STM32L053. L'objectif principal était de concevoir un système interactif et adaptable qui ajuste la couleur de la LED en fonction des valeurs lues à partir d'une photorésistance et d'un potentiomètre. Ce rapport présente en détail le contexte, l'idée générale du projet, son organisation, et les résultats obtenus.

---

## II. Détails du Projet

### 1. Contexte et Objectifs

#### **Objectif** :

Le principal objectif de ce projet est de créer un système de contrôle de LED RGB innovant et interactif, en exploitant les capacités d'un microcontrôleur STM32L053 et en utilisant un potentiomètre et une photorésistance comme interfaces utilisateur. Ce système permettra de régler la couleur de la LED RGB en fonction de la luminosité ambiante et des préférences de l'utilisateur, offrant ainsi une expérience visuelle personnalisée et adaptative.

#### **Contexte** :

Aujourd'hui, avec la croissance rapide de l'Internet des objets (IoT) et des dispositifs intelligents, il existe un besoin croissant de solutions de contrôle de l'éclairage plus flexibles, interactives et écoénergétiques. Les LED RGB offrent une gamme de couleurs étendue et peuvent être utilisées dans une variété d'applications, allant de l'éclairage domestique à l'affichage de données en temps réel.

En intégrant un microcontrôleur STM32L053 avec des capteurs de lumière et de mouvement, ce projet vise à créer un système autonome et adaptable qui peut ajuster dynamiquement l'éclairage en fonction des conditions environnementales et des préférences de l'utilisateur. Par exemple, dans un contexte de domotique, ce système pourrait ajuster automatiquement l'éclairage d'une pièce en fonction de la luminosité extérieure et des activités des occupants, améliorant ainsi le confort et l'efficacité énergétique.

En permettant aux utilisateurs de régler manuellement la couleur de la LED RGB via un potentiomètre, ce système offre également une interaction tactile et ludique, permettant aux utilisateurs de personnaliser leur environnement lumineux selon leurs goûts et leurs besoins spécifiques.

En résumé, ce projet vise à démontrer les capacités polyvalentes et les possibilités d'innovation offertes par les microcontrôleurs et les dispositifs électroniques dans le domaine de l'éclairage intelligent et adaptatif.

### 2. Matériel Utilisé

- Microcontrôleur STM32L053 (Nucleo-L053R8)
- LED RGB L-154A4SURKQBDZGW
- Photorésistance (capteur de luminosité) LDR1000
- Potentiomètre

### 3. Organisation et Répartition des Tâches

Ce projet a été réalisé seule. J'ai donc programmer le microcontrôleur, l'intégration des capteurs et des actionneurs. Mais aussi fais la conception du schéma électrique, du montage du circuit sur la carte de développement.

### 4. Architecture Matérielle

Le système est basé sur un microcontrôleur STM32L053 qui est connecté à une LED RGB, une photorésistance et un potentiomètre. Le schéma électrique a été conçu et implémenté sur la carte de développement Nucleo-L053R8 à l'aide du logiciel de conception de circuits Kicad.

![schema](https://github.com/AlphaxHotelxMikexEchoxDelta/POC_micro/assets/95902084/48b553ba-e3cb-4f9e-bbd1-a34507a46959)

### 5. Structure du Programme

Le programme principal est divisé en plusieurs parties :
- Initialisation des périphériques : configuration des ports GPIO, initialisation de l'ADC pour la lecture des valeurs analogiques.
- Fonctions de contrôle de la LED RGB : fonctions pour allumer, éteindre et vérifier l'état de la LED RGB en fonction des valeurs lues des capteurs.
- Boucle Principale : lecture périodique des valeurs de la photorésistance et du potentiomètre, et ajustement de la couleur de la LED RGB en conséquence.

### 6. Arborescence du projet

```
.
├── driver
│   ├── ADC.c
│   ├── ADC.h
│   ├── led.c
│   ├── led.h
│   ├── rgb.c
│   └── rgb.h
├── gpio.c
├── main.c
├── stm32l0xx_it.c
├── syscalls.c
├── sysmem.c
├── system_stm32l0xx.c
└── usart.c
```

---

## III. Développement du Projet

### 1. Initialisation et Configuration

Le programme commence par inclure les en-têtes nécessaires pour les différentes bibliothèques et modules utilisés, y compris ceux pour la gestion de l'USART, des GPIO, et des fonctions spécifiques de l'ADC et des LED RGB.

```c
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "driver/rgb.h"
#include "driver/ADC.h"
#include "driver/led.h"
#include "stm32l053xx.h"
```

### 2. Déclaration des Variables et Fonctions

Les variables globales `LUMOS` et `MOUAHAHAHAHA` sont utilisées pour stocker les valeurs lues des capteurs. Les prototypes des fonctions de gestion de l'horloge et des erreurs sont également déclarés.

```c
void SystemClock_Config(void);

RGB_TypeDef bleu;
RGB_TypeDef rouge;
RGB_TypeDef vert;

int LUMOS;
int MOUAHAHAHAHA;
```

### 3. Fonctions Utilitaires

#### a. Vérification de la Luminosité

La fonction `is_light_up` vérifie si la valeur lue de la photorésistance est inférieure à un seuil, indiquant une faible luminosité.

```c
int is_light_up(int light){
    if( light <= 1000 ){ return 1; }
    else{ return 0; }
}
```

#### b. Vérification de l'Orientation

La fonction `is_Babord` vérifie si la valeur lue du potentiomètre est supérieure à un certain seuil.

```c
int is_Babord(int hihihihi){
    if( hihihihi >= 1000 ){ return 1; }
    else{ return 0; }
}
```

### 4. Fonction Principale de Contrôle des LEDs

La fonction `Alumm_la_lumiere_ya_zbi` contrôle l'état des LEDs en fonction des valeurs lues des capteurs. Selon les valeurs de `LUMOS` et `MOUAHAHAHAHA`, elle allume ou éteint les LEDs rouge, verte et bleue.

```c
void Alumm_la_lumiere_ya_zbi(int LUMOS, int MOUAHAHAHAHA){
    if (is_Babord(MOUAHAHAHAHA) && !is_light_up(LUMOS)) {
        Rgb_turnOn(&rouge);
        Rgb_turnOff(&vert);
        Rgb_turnOff(&bleu);
    }
    else if (!is_Babord(MOUAHAHAHAHA) && is_light_up(LUMOS)) {
        Rgb_turnOff(&rouge);
        Rgb_turnOn(&vert);
        Rgb_turnOff(&bleu);
    }
    else if (!is_Babord(MOUAHAHAHAHA) && !is_light_up(LUMOS)) {
        Rgb_turnOff(&rouge);
        Rgb_turnOff(&vert);
        Rgb_turnOn(&bleu);
    }
}
```

### 5. Fonction Principale

#### a. Initialisation des Périphériques

La fonction `main` initialise les périphériques nécessaires, y compris le système d'horloge, les GPIO et l'USART.

```c
int main(void)
{
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();
```

#### b. Initialisation des LEDs et de l'ADC

Les LEDs sont initialisées sur les ports GPIO appropriés, et l'ADC est configuré pour lire les valeurs des capteurs.

```c
    Rgb_init(&rouge, GPIOB, 0);
    Rgb_init(&bleu, GPIOC, 0);
    Rgb_init(&vert, GPIOC, 1);

    ADC_init(ADC1, 12, 0);
```

#### c. Boucle Principale

La boucle principale lit les valeurs des capteurs et appelle la fonction de contrôle des LEDs pour ajuster leur état en conséquence.

```c
    while(1){
        LUMOS = ADC_read(ADC1, 0);
        MOUAHAHAHAHA = ADC_read(ADC1, 1);
        Alumm_la_lumiere_ya_zbi(LUMOS, MOUAHAHAHAHA);
    }
}
```

---

## IV. Conclusion

Ce projet nous a permis d'acquérir des connaissances et des compétences importantes dans le domaine de la programmation embarquée et de l'électronique. Nous avons surmonté plusieurs défis techniques, notamment la configuration des périphériques et l'intégration des capteurs avec le microcontrôleur. Des améliorations potentielles pourraient être apportées au projet, telles que l'ajout de fonctionnalités supplémentaires comme la communication sans fil ou la mise en œuvre d'un algorithme d'ajustement de couleur plus sophistiqué.

---

Ce rapport présente une vue d'ensemble du projet, en mettant en évidence le contexte, les objectifs, l'organisation, la mise en œuvre et les résultats obtenus. Il est accompagné des codes source du projet ainsi que d'une vidéo de démonstration pour illustrer son fonctionnement. Ce dossier est soumis conformément aux exigences spécifiées et représente notre travail collaboratif et notre apprentissage dans le cadre de ce projet.

---
