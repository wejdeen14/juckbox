# Jukebox Virtuel en C

## Résumé du Programme

Ce programme en langage C permet de gérer un **jukebox virtuel**, qui contient des albums musicaux. Chaque album est composé de chansons. Le programme offre plusieurs fonctionnalités pour :

- Saisir, afficher et rechercher des albums et des chansons.
- Déterminer l'album le plus long en termes de durée totale.
- Ajouter un nouvel album dans le jukebox.

## Structure du Programme

### Structures de données

- **`chanson_t`** : Représente une chanson avec son titre et sa durée en secondes.
- **`album_t`** : Représente un album contenant un titre, un artiste, une année, le nombre de chansons et un tableau de chansons.
- **`jukebox_t`** : Représente un jukebox avec un catalogue d'albums, le nombre d'albums et le propriétaire du jukebox.

### Fonctionnalités

- **Saisie de chanson** : Permet d'entrer le titre et la durée d'une chanson.
- **Affichage de chanson** : Affiche le titre et la durée d'une chanson.
- **Saisie d'album** : Permet de saisir un album avec son titre, son artiste, son année et les chansons qu'il contient.
- **Affichage d'album** : Affiche les détails d'un album, incluant ses chansons.
- **Recherche d'une chanson dans un album** : Permet de rechercher une chanson par son titre et d'afficher sa durée si elle est trouvée.
- **Calcul de la durée totale d'un album** : Calcule la somme des durées de toutes les chansons d'un album.
- **Insertion d'un album** : Permet d'ajouter un nouvel album dans le jukebox, en vérifiant que l'album n'est pas déjà présent.
- **Album le plus long** : Trouve l'album avec la plus longue durée totale dans le jukebox.

### Interface Utilisateur

Le programme propose un **menu interactif** avec les options suivantes :

- **Saisie d'un jukebox** : Créer un jukebox avec plusieurs albums.
- **Affichage d'un jukebox** : Afficher tous les albums du jukebox.
- **Recherche d'une chanson dans un album** : Rechercher une chanson spécifique dans un album et afficher sa durée.
- **Afficher l'album le plus long** : Afficher le titre et l'artiste de l'album ayant la durée totale la plus longue.
- **Insertion d'un album** : Ajouter un album au jukebox.
- **Quitter** : Quitter le programme proprement.

## Utilisation du Programme

Lorsque vous exécutez le programme, vous serez invité à choisir une option parmi les suivantes :

1. **Saisie d'un jukebox** : Créer un jukebox avec plusieurs albums.
2. **Affichage d'un jukebox** : Afficher tous les albums du jukebox.
3. **Recherche d'une chanson dans un album** : Rechercher une chanson spécifique dans un album du jukebox et afficher sa durée.
4. **Afficher l'album le plus long** : Afficher le titre et l'artiste de l'album ayant la durée totale la plus longue.
5. **Insertion d'un album** : Ajouter un album au jukebox.
6. **Quitter** : Quitter le programme.


## Exécution du programme

Le programme fonctionne sous n'importe quel compilateur C standard. Pour l'exécuter, assurez-vous d'avoir les bibliothèques nécessaires pour l'entrée/sortie, telles que `stdio.h`, `stdlib.h`, et `string.h`.

### Compilation

```bash
gcc -o jukebox jukebox.c
