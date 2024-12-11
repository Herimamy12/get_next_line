![gnl](get_next_line.jpg)
# get_next_line

## Description

Le projet **get_next_line** consiste à créer une fonction qui permet de lire une ligne à partir d'un fichier ou d'un flux (stdin). La fonction doit renvoyer une ligne complète à chaque appel, et gérer la lecture jusqu'à la fin du fichier ou du flux.

L'objectif de ce projet est d'améliorer la compréhension de la gestion des fichiers, des buffers, et de la mémoire dans le langage C, en particulier la gestion des chaînes de caractères.

## Fonctionnement

La fonction `get_next_line` lit une ligne à la fois à partir d'un fichier ou de l'entrée standard, en prenant en compte les éventuelles nouvelles lignes (`\n`) et en allouant dynamiquement de la mémoire pour stocker chaque ligne lue.

### Partie obligatoire

- La fonction `get_next_line` lit une ligne à partir de l'entrée, et renvoie cette ligne à chaque appel.
- Elle gère les appels successifs et renvoie `NULL` lorsqu'il n'y a plus de données à lire.
  
### Partie bonus

- La version bonus améliore la fonction pour gérer plusieurs descripteurs de fichiers, permettant ainsi de lire plusieurs fichiers ou flux simultanément, tout en maintenant un état de lecture pour chaque descripteur.

## Installation

Clonez le projet depuis GitHub en utilisant la commande suivante :

1. Clonez le repository :

	```bash
	git clone https://github.com/Herimamy12/get_next_line.git

2. Accedez au dossier et compilez le projet en utilisant le Makefile fourni :

	```bash
	cd get_next_line
	make

3. Pour compiler la partie bonus, utilisez :

	```bash
	make bonus

> **Warning pour les étudiants de 42 :**  
> Ce projet contient un **Makefile** pour simplifier la compilation pendant le développement et les tests.  
> Cependant, **il n'y a pas de Makefile prévu pour le vrai projet durant le cursus**. Il vous sera demandé d'implémenter votre propre processus de compilation sans Makefile.  
> Assurez-vous de bien comprendre le fonctionnement des fichiers sources, de l'édition des liens et de la gestion des dépendances afin de respecter les exigences du projet final.

## Utilisation

### Exemple d'utilisation

Une fois la compilation effectuée, vous pouvez utiliser la fonction `get_next_line` dans votre programme C. Voici un exemple simple d'utilisation qui lit les lignes d'un fichier texte :

1. **Exemple d'un main que vous pouvez utilisez :**

	```c
	#include "get_next_line.h"
	#include <fcntl.h>
	#include <stdio.h>

	int main()
	{
		int fd = open("file", O_RDONLY);  // Ouvrir un fichier en lecture seule
		char *line;

		// Lire et afficher chaque ligne du fichier
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);  // Affiche la ligne lue
			free(line);  // Libère la mémoire allouée pour la ligne
		}

		close(fd);  // Fermer le fichier une fois terminé
		return 0;
	}

2. **Exécutez le programme :**
	```bash
	./get_next_line || ./get_next_line_bonus
	```
### Fonctionnement de `get_next_line`

- **Paramètre** : La fonction prend un descripteur de fichier (`int fd`), obtenu généralement par l'appel à `open()` pour ouvrir un fichier. Ce descripteur permet de lire les données du fichier.
- **Valeur de retour** : La fonction retourne une ligne lue du fichier. La ligne est allouée dynamiquement, donc il est important de libérer la mémoire allouée avec `free()` après utilisation.
- **Fin de fichier** : Lorsque la fin du fichier est atteinte ou qu'il n'y a plus de données à lire, la fonction retourne `NULL`.
- **Gestion des nouvelles lignes** : La fonction gère correctement les retours à la ligne (`\n`) et conserve l'état de lecture d'un fichier entre les appels pour reprendre la lecture là où elle s'était arrêtée.

### Bonus : Gestion de plusieurs descripteurs de fichiers

Dans la partie bonus, la fonction est étendue pour pouvoir gérer plusieurs descripteurs de fichiers en même temps. Cela vous permet de lire depuis plusieurs fichiers ou flux simultanément tout en gardant un état de lecture pour chaque descripteur.

Pour utiliser cette fonctionnalité bonus, il suffit de passer un descripteur de fichier différent à chaque appel de `get_next_line`. Ainsi, vous pourrez lire plusieurs fichiers sans interférer entre eux.

## Contribution

Les contributions à ce projet sont les bienvenues ! Si vous souhaitez participer, voici les étapes à suivre :

1. Forkez ce projet.
2. Créez une branche pour chaque fonctionnalité ou correction de bug.
3. Assurez-vous que vos modifications ne cassent pas l'existant et que toutes les fonctionnalités sont correctement testées.
4. Soumettez une Pull Request pour que vos modifications puissent être examinées et fusionnées.

Nous vous encourageons également à ajouter des tests unitaires pour garantir la stabilité du projet et éviter toute régression.

## Remerciements

Un grand merci pour tous ceux qui ont contribué directement ou indirectement à ce projet.
