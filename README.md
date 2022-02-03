# Jeu de la vie ou Game of Life

## Système de versionnement

Une version peut être représentée jusqu'à 3 chiffres :

* Le premier correspondant au changement du niveau développé (équivalent à une modification dite majeure)
* Le deuxième correspondant à l'ajout ou la modification totale d'une fonction ou autre fonctionnalité (équivalent à une modification dite mineure)
* Le troisième correspondant à la correction et à l'optimisation du code (correction de bugs affichant des avertissements lors de la compilation, correction de la syntaxe,...)

Par exemple, la version 1.3.1 correspond au premier niveau avec 3 modifications mineures et une correction/amélioration apportée au code.

## Commandes

#### Archivage au format tar+lzma (extension .tar.xz)
```
make dist
```

#### Création de l'exécutable
```
make
```

#### Suppression des fichiers objets et de l'exécutable
```
make clean
```

#### Création de la documentation
```
make doc
```