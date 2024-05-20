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

### 2. Programme

Le programme principal du projet est écrit en langage C et est conçu pour être exécuté sur le microcontrôleur STM32L053. Voici un aperçu des principales fonctionnalités du programme :

#### Initialisation des Périphériques

Dans la fonction `main()`, les périphériques nécessaires sont initialisés. Cela comprend la configuration des ports GPIO pour contrôler la LED RGB ainsi que l'initialisation de l'ADC (Convertisseur Analogique-Numérique) pour lire les valeurs analogiques du potentiomètre et de la photorésistance.

```c
// Initialisation des périphériques
ADC_init(ADC1, 12, 1); // Initialise l'ADC pour la lecture du potentiomètre
ADC_init(ADC1, 12, 0); // Initialise l'ADC pour la lecture de la photorésistance
Rgb_init(&bleu, GPIOC, 0); // Initialise la LED RGB bleue sur le port C, broche 0
Rgb_init(&rouge, GPIOC, 1); // Initialise la LED RGB rouge sur le port C, broche 1
Rgb_init(&vert, GPIOB, 0); // Initialise la LED RGB verte sur le port B, broche 0
```

#### Boucle Principale

La boucle principale du programme lit périodiquement les valeurs analogiques du potentiomètre et de la photorésistance à l'aide de l'ADC. En fonction de ces valeurs, elle contrôle l'état des LEDs RGB pour ajuster la couleur de la LED en conséquence.

```c
while (1) {
    val_lumiere = ADC_read(ADC1, 0); // Lecture de la valeur de la photorésistance
    val_potentiometre = ADC_read(ADC1, 1); // Lecture de la valeur du potentiomètre
    control_Led_Rgb(val_lumiere, val_potentiometre); // Contrôle de la LED RGB en fonction des valeurs lues
    LL_mDelay(1000); // Délai pour la prochaine lecture
}
```

#### Fonctions de Contrôle de la LED RGB

Les fonctions `Rgb_turnOn()`, `Rgb_turnOff()`, `Rgb_isOn()`, et `Rgb_isOff()` sont utilisées pour allumer, éteindre et vérifier l'état de la LED RGB en fonction des valeurs lues des capteurs.

---

Cette partie met en lumière le fonctionnement du programme, détaillant son initialisation, sa boucle principale et les fonctions utilisées pour contrôler la LED RGB. Ces fonctionnalités permettent d'atteindre l'objectif principal du projet en offrant un éclairage adaptatif en fonction de l'environnement et des préférences de l'utilisateur.

### 3. Matériel Utilisé

- Microcontrôleur STM32L053 (Nucleo-L053R8)
- LED RGB L-154A4SURKQBDZGW
- Photorésistance (capteur de luminosité) LDR1000
- Potentiomètre

### 4. Organisation et Répartition des Tâches

Ce projet a été réalisé seule. J'ai donc programmer le microcontrôleur, l'intégration des capteurs et des actionneurs. Mais aussi fais la conception du schéma électrique, du montage du circuit sur la carte de développement.

### 5. Architecture Matérielle

Le système est basé sur un microcontrôleur STM32L053 qui est connecté à une LED RGB, une photorésistance et un potentiomètre. Le schéma électrique a été conçu et implémenté sur la carte de développement Nucleo-L053R8 à l'aide du logiciel de conception de circuits Kicad.

![schema](https://github.com/AlphaxHotelxMikexEchoxDelta/POC_micro/assets/95902084/48b553ba-e3cb-4f9e-bbd1-a34507a46959)

### 6. Structure du Programme

Le programme principal est divisé en plusieurs parties :
- Initialisation des périphériques : configuration des ports GPIO, initialisation de l'ADC pour la lecture des valeurs analogiques.
- Fonctions de contrôle de la LED RGB : fonctions pour allumer, éteindre et vérifier l'état de la LED RGB en fonction des valeurs lues des capteurs.
- Boucle Principale : lecture périodique des valeurs de la photorésistance et du potentiomètre, et ajustement de la couleur de la LED RGB en conséquence.

---

## III. Conclusion

Ce projet nous a permis d'acquérir des connaissances et des compétences importantes dans le domaine de la programmation embarquée et de l'électronique. Nous avons surmonté plusieurs défis techniques, notamment la configuration des périphériques et l'intégration des capteurs avec le microcontrôleur. Des améliorations potentielles pourraient être apportées au projet, telles que l'ajout de fonctionnalités supplémentaires comme la communication sans fil ou la mise en œuvre d'un algorithme d'ajustement de couleur plus sophistiqué.

---

Ce rapport présente une vue d'ensemble du projet, en mettant en évidence le contexte, les objectifs, l'organisation, la mise en œuvre et les résultats obtenus. Il est accompagné des codes source du projet ainsi que d'une vidéo de démonstration pour illustrer son fonctionnement. Ce dossier est soumis conformément aux exigences spécifiées et représente notre travail collaboratif et notre apprentissage dans le cadre de ce projet.

---
