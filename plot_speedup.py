import matplotlib.pyplot as plt
import numpy as np

# Taille des matrices N
N = 512

# Temps mesuré pour 1 Thread (T1_ref) : Nous utilisons le meilleur temps séquentiel mesuré
T1_REF = 1.793901  

# Temps d'exécution mesurés pour P=1, 2, 4, 8 (Temps Parallèle TP, qui est la 2e valeur affichée)
temps_mesures = np.array([3.338666, 0.851352, 1.240579, 0.762383]) 

# Nombre de threads (P)
threads = np.array([1, 2, 4, 8])

# Calcul du Speedup (S_P = T1_REF / T_P)
speedup = T1_REF / temps_mesures

# Calcul de l'Accélération Théorique (Idéale)
speedup_ideal = threads

# ==============================================================================
# GÉNÉRATION DU GRAPHIQUE
# ==============================================================================

plt.figure(figsize=(10, 6))
plt.style.use('seaborn-v0_8-darkgrid')

# 1. Courbe d'accélération mesurée (vos résultats)
plt.plot(threads, speedup, marker='o', linestyle='-', color='blue', label='Speedup mesuré (OpenMP)')

# 2. Courbe d'accélération théorique (la ligne idéale)
plt.plot(threads, speedup_ideal, linestyle='--', color='red', label='Speedup théorique (Linéaire)')

# Configuration des axes et du titre
plt.title(f"Analyse du Speedup pour la Multiplication de Matrices ({N}x{N})", fontsize=16)
plt.xlabel("Nombre de Threads (P)", fontsize=12)
plt.ylabel("Accélération (Speedup $S_P$)", fontsize=12)

# Définition des ticks pour l'axe X (correspond aux threads testés)
plt.xticks(threads)
plt.yticks(np.arange(0, 9, 1)) 

plt.legend()
plt.grid(True)
plt.tight_layout()

# Sauvegarder le graphique dans le dépôt GitHub (au même emplacement que le script)
plt.savefig("speedup_graph.png")
print("Le graphique 'speedup_graph.png' a été généré dans votre dossier actuel.")