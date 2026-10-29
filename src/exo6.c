#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int N, i, status, val, max = -1;

    printf("Introduire N : ");
    fflush(stdout);                  /* vider le tampon avant fork */
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        pid_t pid = fork();
        if (pid == 0) {              /* fils : génère et renvoie */
            srand(getpid());
            val = rand() % 100;
            printf("Fils %d : valeur = %d\n", i + 1, val);
            exit(val);
        }
        /* le père continue la boucle et crée le fils suivant */
    }

    for (i = 0; i < N; i++) {        /* le père attend les N fils */
        wait(&status);
        val = WEXITSTATUS(status);
        if (val > max) max = val;
    }
    printf("Père : la plus grande valeur est %d\n", max);
    return 0;
}
