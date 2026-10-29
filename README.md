# TP1 – Les processus (Système d'exploitation)

TP du module **Système d'exploitation**, M1 SII, USTHB (2023/2024).
Thème : création et synchronisation de processus sous Linux en langage C.

## Exercices

| Fichier | Description |
|---|---|
| `src/exo1a.c` | Un père et un fils : affichage des PID |
| `src/exo1b.c` | Le père lance deux fils |
| `src/exo2.c` | Deux fils envoient une valeur aléatoire au père, qui affiche la plus grande |
| `src/exo3.c` | Trois fils saisissent x, y, z ; le père calcule x*y+z |
| `src/exo4.c` | Exécuter `ls` avec `execlp` |
| `src/carre.c`, `src/racine.c`, `src/calcule.c` | `calcule` lance `carre` ou `racine` dans un fils |
| `src/exo6.c` | Exercice 2 avec N fils (N saisi par l'utilisateur) |

## Notions utilisées

- `fork()` : créer un processus fils
- `getpid()` / `getppid()` : PID du processus et de son père
- `wait()` / `waitpid()` : le père attend ses fils
- `exit(v)` + `WEXITSTATUS()` : le fils renvoie une valeur (0 à 255) au père
- `execlp()` : remplacer le programme courant par un autre

## Compilation et exécution

```bash
make                  # compile tout dans le dossier bin/
./bin/exo2            # exécuter un programme
cd bin && ./calcule   # calcule doit être lancé depuis bin/ (il appelle ./carre et ./racine)
make clean            # supprimer les programmes compilés
```

Ou à la main :

```bash
gcc src/exo2.c -o exo2
gcc src/racine.c -o racine -lm   # -lm pour la bibliothèque math (sqrt)
```
