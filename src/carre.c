#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage : ./carre valeur\n");
        return 1;
    }
    int val = atoi(argv[1]);
    printf("Le carré de %d est %d\n", val, val * val);
    return 0;
}
