#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int fds[2];
    pipe(fds);
    printf("parent pid: %d\n", getpid());
    pid_t pid = fork();
    if (pid == 0) {
        close(fds[1]);
        char buffer[6];
        read(fds[0], buffer, sizeof(buffer));
        printf("Read from pipe bridging processes: '%s' (coming from %d inside %d).\n", buffer, getppid(), getpid());
        close(fds[0]);
        return 0;
    }
    close(fds[0]);
    write(fds[1], "hello", 6);
    waitpid(pid, NULL, 0);
    close(fds[1]);

    return 0;
}
