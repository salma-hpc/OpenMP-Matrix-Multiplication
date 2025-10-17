#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> // Bibliothèque OpenMP

// Taille des matrices N x N
// CONSEIL : Commencez par N=1024 ou N=2048 si votre machine le permet, 
// sinon utilisez N=512 pour un test rapide.
#define N 512 

// Définition des matrices globales
double A[N][N], B[N][N], C[N][N];

// Fonction d'initialisation des matrices
void init_matrices() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)rand() / RAND_MAX;
            B[i][j] = (double)rand() / RAND_MAX;
            C[i][j] = 0.0;
        }
    }
}

// Fonction de multiplication séquentielle
void multiply_sequential() {
    // Déclaration des variables au début de la fonction (Correction de la portée)
    int i, j, k; 
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Fonction de multiplication parallèle avec OpenMP
void multiply_parallel() {
    // Déclaration des variables au début de la fonction (Correction de la portée)
    int i, j, k; 
    
    // Utiliser la directive pragma pour paralléliser la boucle 'i'
    // 'private(j, k)' assure que chaque thread a sa propre copie de ces indices (bonne pratique)
    #pragma omp parallel for private(j, k) shared(A, B, C)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    double start_time, end_time;

    // ------------------------------------
    // 1. VERSION SÉQUENTIELLE (utilisée comme référence T1)
    // ------------------------------------
    init_matrices(); 
    start_time = omp_get_wtime();

    multiply_sequential();

    end_time = omp_get_wtime();
    double time_sequential = end_time - start_time;
    printf("Matrice de taille N=%d\n", N);
    printf("Temps SÉQUENTIEL (T1, secondes) : %.6f\n", time_sequential);

    // ------------------------------------
    // 2. VERSION PARALLÈLE (pour P threads)
    // ------------------------------------
    init_matrices(); 
    
    // Déterminer le nombre de threads à utiliser
    int num_threads = omp_get_max_threads();
    if (argc > 1) {
        num_threads = atoi(argv[1]); // Lire le nombre de threads depuis la ligne de commande
    }
    omp_set_num_threads(num_threads);
    
    start_time = omp_get_wtime();

    multiply_parallel();

    end_time = omp_get_wtime();
    double time_parallel = end_time - start_time;
    
    printf("Nombre de THREADS utilisés (P) : %d\n", num_threads);
    printf("Temps PARALLÈLE (TP, secondes) : %.6f\n", time_parallel);
    printf("Speedup (T1/TP) : %.2f\n", time_sequential / time_parallel);

    return 0;
}