#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int val, choix;
    char param[20];

    printf("Entrer une valeur : ");
    scanf("%d", &val);
    printf("Choix (1 = carré, 2 = racine) : ");
    fflush(stdout);
    scanf("%d", &choix);

    sprintf(param, "%d", val);       /* entier -> chaîne */

    pid_t pid = fork();
    if (pid == 0) {
        if (choix == 1)
            execlp("./carre", "carre", param, NULL);
        else if (choix == 2)
            execlp("./racine", "racine", param, NULL);
        else
            printf("Choix invalide\n");
        exit(1);                     /* échec exec ou choix invalide */
    }
    wait(NULL);
    return 0;
}
