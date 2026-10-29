#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Le fork() a échoué\n");
        return 1;
    }
    if (pid == 0) {
        /* code du fils */
        printf("Je suis le processus fils, mon PID est : %d "
               "et le PID de mon père est : %d\n", getpid(), getppid());
    } else {
        /* code du père : pid = PID du fils */
        printf("Je suis le processus père, mon PID est : %d "
               "et le PID de mon fils est : %d\n", getpid(), pid);
        wait(NULL);   /* attendre la fin du fils */
    }
    return 0;
}
