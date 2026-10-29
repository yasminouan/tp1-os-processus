#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p1, p2;
    int s1, s2, v1, v2;

    p1 = fork();
    if (p1 == 0) {
        srand(getpid());             /* graine différente */
        int v = rand() % 100;
        printf("Fils 1 : valeur = %d\n", v);
        exit(v);                     /* valeur envoyée au père */
    }

    p2 = fork();
    if (p2 == 0) {
        srand(getpid());
        int v = rand() % 100;
        printf("Fils 2 : valeur = %d\n", v);
        exit(v);
    }

    waitpid(p1, &s1, 0);
    waitpid(p2, &s2, 0);
    v1 = WEXITSTATUS(s1);            /* valeur du fils 1 */
    v2 = WEXITSTATUS(s2);

    printf("Père : la plus grande valeur est %d\n",
           (v1 > v2) ? v1 : v2);
    return 0;
}
