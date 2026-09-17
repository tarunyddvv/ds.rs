#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    printf("I'm unique and just get printed once.\n");
    pid_t pid = fork();
    bool parent = pid != 0;
    if((random() % 2 == 0) == parent) sleep(1);
    if (parent) waitpid(pid, NULL, 0);
    printf("I get printed twice (this one is being printed from the %s).\n", parent ? "parent" : "child");

    return 0;
}
