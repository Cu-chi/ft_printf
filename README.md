# ft_printf
⚠️ Disclaimer : Ce projet est rendu public à titre pédagogique ; le plagiat étant strictement interdit au sein du cursus 42, merci de ne pas copier-coller ce code sans le comprendre.

#### 📖 Résumé
L'objectif de ce projet est de recoder la célèbre fonction printf de la bibliothèque standard du C. Ce projet permet d'approfondir la gestion des fonctions variadiques (nombre variable d'arguments) et de structurer un code capable de parser et formater des chaînes de caractères complexes.
---
#### 🚀 Fonctionnalités
Mon implémentation reproduit le comportement de l'original, y compris la gestion du buffer et le retour du nombre de caractères imprimés.

Conversions gérées
 - `%c` : Caractère unique.
 - `%s` : Chaîne de caractères.
 - `%p` : Adresse de pointeur (en hexadécimal).
 - `%d` / `%i` : Entier décimal signé.
 - `%u` : Entier décimal non signé.
 - `%x` : Hexadécimal (minuscules).
 - `%X` : Hexadécimal (majuscules).
 - `%%` : Le signe pourcentage lui-même.

**Bonus**
Cette version inclut la gestion complète des combinaisons de flags suivants :
 - Alignement et Remplissage : `-` (alignement à gauche), `0` (remplissage avec des zéros).
 - Précision et Largeur : `.` (précision), gestion de la largeur de champ minimale.
 - Préfixes et Signes : `#` (préfixe 0x/0X), `+` (force l'affichage du signe), ` ` (espace pour les nombres positifs).
