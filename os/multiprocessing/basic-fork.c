#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Greetings from process %d! (parent %d)\n", getpid(), getppid());
    pid_t pid = fork();
    printf("Bye-bye from process %d! (parent %d)\n", getpid(), getppid());

    return 0;
}
