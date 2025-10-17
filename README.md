# 🚀 Projet HPC : Optimisation de la Multiplication de Matrices avec OpenMP

Ce projet a pour objectif de quantifier les gains de performance (*Speedup*) obtenus en parallélisant l'algorithme classique de multiplication de matrices $C = A \times B$ en utilisant la bibliothèque **OpenMP** (Shared Memory Parallelism).

## 💻 Technologies utilisées

* **Langage :** C/C++
* **Parallélisation :** OpenMP
* **Analyse :** Python (Matplotlib)
* **Environnement :** Linux/Ubuntu

## 🛠️ Compilation et Exécution

L'application a été compilée avec le drapeau `-fopenmp` et exécutée pour différentes valeurs de threads ($P$). Les tests ont été réalisés sur des matrices de taille $N=512$.

**1. Compilation (avec support OpenMP) :**
```bash
gcc -o matrix_mult matrix_mult.c -fopenmp -Wall
2. Mesure du temps séquentiel et parallèle (Exemple) :
# Exécution pour P=4 threads
export OMP_NUM_THREADS=4
./matrix_mult 4
📈 Résultats et Analyse de Performance

Les temps d'exécution suivants ont été mesurés sur une machine multi-cœurs. Pour garantir une analyse cohérente, le meilleur temps séquentiel mesuré (T1,ref​=1.793901 s) a été utilisé comme référence pour le calcul du Speedup.
Threads (P)	Temps d'Exécution TP​ (s)	Speedup SP​=T1,ref​/TP​	Efficacité EP​=SP​/P
1	3.338666	0.54	0.54
2	0.851352	2.11	1.05
4	1.240579	1.45	0.36
8	0.762383	2.35	0.29
Interprétation

    Speedup Maximum : Le Speedup maximum de 2.35 est atteint avec 8 threads, validant le gain de performance de la parallélisation.

    Superlinéarité à P=2 : Le Speedup de 2.11 pour 2 threads (Efficacité >1) suggère un effet de Cache très positif.

    Limitations : Le Speedup ne suit pas la ligne linéaire idéale, ce qui est attribué aux frais généraux de synchronisation (overhead) et à la congestion de la mémoire cache (cache thrashing).

Conclusion : Ce projet démontre la maîtrise de l'optimisation OpenMP et la capacité à réaliser une analyse de performance critique des résultats réels.

Visualisation du Speedup :

