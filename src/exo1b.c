#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) {                 /* premier fils */
        printf("Fils 1 : PID = %d, PID de mon père = %d\n",
               getpid(), getppid());
        return 0;                    /* le fils s'arrête ici */
    }

    pid2 = fork();
    if (pid2 == 0) {                 /* deuxième fils */
        printf("Fils 2 : PID = %d, PID de mon père = %d\n",
               getpid(), getppid());
        return 0;
    }

    /* seul le père arrive ici */
    printf("Père : PID = %d, mes fils : %d et %d\n",
           getpid(), pid1, pid2);
    wait(NULL);
    wait(NULL);
    return 0;
}
