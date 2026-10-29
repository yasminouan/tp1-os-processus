#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage : ./racine valeur\n");
        return 1;
    }
    int val = atoi(argv[1]);
    if (val < 0) {
        printf("Racine carrée impossible pour un nombre négatif\n");
        return 1;
    }
    printf("La racine carrée de %d est %.2f\n", val, sqrt(val));
    return 0;
}
