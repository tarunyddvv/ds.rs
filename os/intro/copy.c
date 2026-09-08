#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  umask(077);
  int fdin = open(argv[1], O_RDONLY);
  int fdout = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);
  while (true) {
    char buffer[1024];
    ssize_t bytesRead = read(fdin, buffer, sizeof(buffer));
    if (bytesRead == 0)
      break;
    size_t bytesWritten = 0;
    while (bytesWritten < bytesRead) {
      bytesWritten +=
          write(fdout, buffer + bytesWritten, bytesRead - bytesWritten);
    }
  }

  close(fdin);
  close(fdout);
  return 0;
}
