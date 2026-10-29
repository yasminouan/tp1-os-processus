#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t f1, f2, f3;
    int s1, s2, s3, x, y, z;

    f1 = fork();
    if (f1 == 0) {
        int x;
        printf("Fils f1 - introduire x : ");
        scanf("%d", &x);
        exit(x);
    }
    waitpid(f1, &s1, 0);   /* on attend f1 avant de créer f2 */

    f2 = fork();
    if (f2 == 0) {
        int y;
        printf("Fils f2 - introduire y : ");
        scanf("%d", &y);
        exit(y);
    }
    waitpid(f2, &s2, 0);   /* idem pour f2 */

    f3 = fork();
    if (f3 == 0) {
        int z;
        printf("Fils f3 - introduire z : ");
        scanf("%d", &z);
        exit(z);
    }
    waitpid(f3, &s3, 0);

    x = WEXITSTATUS(s1);
    y = WEXITSTATUS(s2);
    z = WEXITSTATUS(s3);
    printf("Père : %d * %d + %d = %d\n", x, y, z, x * y + z);
    return 0;
}
