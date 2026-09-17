#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("Before.\n");
    pid_t pid = fork();
    printf("After.\n");
    if (pid == 0) { // child
        printf("I am the child, and the parent will wait up for me.\n");
        return 110;
    } else { // parent
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child exited with status %d.\n", WEXITSTATUS(status));
        } else {
            printf("Child terminated abnormally.\n");
        }
    }
    return 0;
}
