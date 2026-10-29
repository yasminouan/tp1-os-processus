#include <stdio.h>
#include <unistd.h>

int main() {
    execlp("ls", "ls", "-l", NULL);   /* exécute ls -l */
    perror("execlp");                 /* seulement si échec */
    return 1;
}
