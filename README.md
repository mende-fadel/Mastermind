# Projet Mastermind MAACHE MUKOKA MENDE

Le jeu "Mastermind" vous invite à deviner une séquence secrète de 4 couleurs en 10 tentatives ou moins.

## Commande

1. Compilez le programme avec la commande : 

```bash
make
```

2. Creer la documentation avec la commande : 

```bash
make doc
```

3. Creer l'archive avec la commande : 

```bash
make archive
```

4. Supprimer les fichiers objets -la Documentation- L'Archive :

```bash
make clean 
```


## Jouer

5. Lancer le programme avec la commande : 

```bash
make run
```


Suivez les instructions à l'écran pour choisir le mode de jeu et commencer à deviner la séquence de couleurs.


## Manuel Développeur

### Commits

- `feat` : Nouvelle fonctionnalité
- `fix` : Correction de bug
- `refact` : Modification de la structure du code sans ajouter de fonctionnalité
- `style` : Modification de l'indentation, des espaces, des commentaires, etc.
- `docs` : Modification de la documentation du code ou du projet


exemple de commit : 

```bash
git commit -m "feat: ajout de la fonctionnalité de chargement de fichier "
```

### Architecture du Code

- `main.c` : Point d'entrée du jeu, gère la logique principale.
- `jeu.c` : Contient les fonctions de jeu.
    Ces fonctions gèrent la logique principale du jeu, y compris l'initialisation, l'évaluation des suppositions du joueur et la vérification de la victoire.
    par exemple: void afficher_regles(): Affiche les règles du jeu Mastermind.
                 int choisir_mode_couleur(): Permet au joueur de choisir d'utiliser la couleur pour l'affichage.


- `random.c` : Contient les fonctions de génération aléatoire.
    En detaille Ces fonctions génèrent des couleurs aléatoires ou une combinaison aléatoire pour la séquence secrète.

- `affichage.c` : Contient les fonctions d'affichage.
    En detaille cette fonction fournit des methodes pour afficher les differentes elements du jeu, tels que les regles, les resultats des tentatives et les messages de victoire ou de defaite.

- `input.c` : Contient les fonctions de saisie utilisateur.
    en detaille Ces fonctions permettent à l'utilisateur de saisir une combinaison et vérifient si elle est valide.

    void lire_combinaison(char *supposition): Lit une combinaison saisie par l'utilisateur.
    int est_valide(const char *supposition): Vérifie si la combinaison saisie est valide.


- `chargeur_fichier.c` : Contient les fonctions de chargement de fichier.
    En detaille cette fonction permet de charger une sequence de couleurs a partir d'un fichier specifié.

- `bibliotheque_couleur.c` : Contient les fonctions de gestion des couleurs.

### Debugger le programme

Pour debugger un fichier, vous pouvez utiliser l'outil `gdb` via le makefile avec la commande : 

```bash
make debug FILE=./chemin/du/fichier.c
```




### Verifier les fuites de mémoire

Pour verifier les fuites de mémoire d'un fichier, vous pouvez utiliser l'outil `valgrind` via le makefile avec la commande : 

```bash
make memcheck FILE=./chemin/du/fichier.c
```

Pour verifier les fuites de mémoire du programme, vous pouvez utiliser l'outil `valgrind` via le makefile avec la commande : 

```bash
valgrind --leak-check=yes ./build/mastermind
```

### Contribution 

Pour contribuer au projet, veuillez suivre les étapes suivantes :
- créer une branche de développement avec la commande : 

```bash
git branch dev-NOM
```

- creer une issue sur le projet pour la fonctionnalité que vous souhaitez ajouter
exemple : 
```bash
fix: correction du bug de l'affichage
```
ou 
```bash
feat: ajout de la fonctionnalité de chargement de fichier
```

- creer une branche pour resoudre l'issue: 

NB: il est important d'associé la branche pour resoudre l'issue avec l'issue correspondante

- merge la branche issue avec la branche de développement et la branche de développement avec la branche principale


## Rapport du Projet


### Façon de développer

Nous avons décidé de d'abord développer les fonctionnalités de base du jeu. Ensuite nous avons ajouter les fonctionnalités avancées. Nous avons travailler en parallèle sur les différentes fonctionnalités du projet. Tout en gardant une branche principale stable et proteger.
Tout d'abord nous avons travaille sur une structure basique tel que :

- build => contient les fichiers compilés
- data => contient la combinaison secrete
- lib => contient la bibliotheque
- src => contient les fichiers sources et les fichiers d'en-tête
- Doxyfile => fichier de configuration pour la documentation
- README.md => fichier de description du projet
- Makefile  => fichier de commande pour compiler le programme et developper le projet

### Organisation du projet

Le groupe a été organisé de manière collaborative, avec des membres assignés à différentes tâches telles que la conception, le développement, les tests et la documentation. Des réunions régulières ont été tenues pour discuter de l'avancement, des obstacles rencontrés et des prochaines étapes.

**Conception :**
- Mohamed MAACHE <mohamed.maache@etu.unistra.fr>

**Développement :**
- Mohamed MAACHE <mohamed.maache@etu.unistra.fr>
- Fadel MENDE <fadel.mende@etu.unistra.fr>
- Serge MUKOKA <serge.mukoka@etu.unistra.fr>

**Tests :**
- Fadel MENDE <fadel.mende@etu.unistra.fr>
- Mohamed MAACHE <mohamed.maache@etu.unistra.fr>
- Serge MUKOKA <serge.mukoka@etu.unistra.fr>
                
**Documentation :**
- Serge MUKOKA <serge.mukoka@etu.unistra.fr>
- Fadel MENDE <fadel.mende@etu.unistra.fr>
- Mohamed MAACHE <mohamed.maache@etu.unistra.fr>

Nous travaillons sur une organisation git qui est nommée "git flow". Cette organisation est basée sur la création de branches pour chaque fonctionnalité. Nous avons donc les branches suivantes :
- `main` : branche principale du projet
- `dev-NOM` : branche de développement de chaque membre du groupe
- `feature-NOMFEATURE-NOM` : branche de développement de chaque fonctionnalité
- `NB_ISSUE-NOM` : branche de correction de bug

Ceci nous permet de travailler en parallèle sur les différentes fonctionnalités du projet, tout en gardant une branche principale stable et protégée.
### Processus de développement du projet:

1. **Conception :** 
   - Les fonctionnalités du jeu ont été identifiées, y compris le chargement de la séquence, la lecture des entrées du joueur, l'évaluation des suppositions et l'affichage des résultats.
   
2. **Développement :** 
   - Le code a été divisé en plusieurs fichiers pour une meilleure organisation et modularité. Chaque fonctionnalité a été implémentée dans un fichier séparé, puis intégrée dans le programme principal.
   
3. **Tests :** 
   - Des tests unitaires ont été effectués pour chaque fonction pour s'assurer de son bon fonctionnement. Des jeux de tests ont également été utilisés pour valider le jeu dans différents scénarios.
   
4. **Documentation :** 
   - Des commentaires ont été ajoutés dans le code pour expliquer chaque fonction et sa logique. Un rapport de projet a été rédigé pour fournir une vue d'ensemble du travail accompli.

### Défis rencontrés et adaptation:

1. **Gestion des couleurs :** 
   - La gestion des couleurs dans l'affichage a posé un défi, notamment pour l'utilisation des codes ANSI pour les couleurs. Des fonctions ont été créées pour faciliter l'affichage coloré.
   
2. **Chargement de la séquence :** 
   - La lecture de la séquence à partir d'un fichier et sa validation ont nécessité une attention particulière pour s'assurer de la robustesse du programme. Des fonctions de chargement et de validation ont été implémentées.
   
3. **Adaptation aux modifications :** 
   - Au fur et à mesure du développement, des ajustements ont été nécessaires pour améliorer l'expérience utilisateur et la robustesse du jeu. Des révisions fréquentes ont été effectuées pour répondre aux besoins changeants.

### Choix de conception:

1. **Modularité :** 
   - Le code a été conçu de manière modulaire pour faciliter la maintenance et les futures extensions. Chaque fonctionnalité a été encapsulée dans des fonctions distinctes pour favoriser la réutilisation.
   
2. **Utilisation de structures :** 
   - Des structures ont été utilisées pour représenter les résultats des évaluations de suppositions, ce qui a simplifié la manipulation des données et amélioré la lisibilité du code.
   
3. **Gestion des modes :** 
   - Le jeu a été conçu pour prendre en charge deux modes : facile et difficile, offrant ainsi une expérience adaptable aux préférences des joueurs.

### Fonctionnalités supplémentaires:

1. **Animation de démarrage :** 
   - Une animation de démarrage a été ajoutée pour rendre l'expérience utilisateur plus attrayante.
   
2. **Choix de la couleur de l'affichage :** 
   - Les joueurs peuvent choisir d'activer ou de désactiver l'affichage coloré, offrant ainsi une personnalisation supplémentaire.

## Conclusion:

Le développment du jeu Mastermind a été une expérience enrichissante, mettant en lumière les compétences en programmation, en collaboration et en résolution de problèmes du groupe. Grâce à une approche méthodique, des défis ont été relevés, des solutions ont été trouvées et un jeu fonctionnel et divertissant a été créé. La flexibilité du code permettra d'ajouter facilement de nouvelles fonctionnalités à l'avenir, offrant ainsi aux joueurs une expérience de jeu encore plus immersive.


    




