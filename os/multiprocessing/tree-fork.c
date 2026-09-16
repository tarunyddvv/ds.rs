#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


static const char *kTrail = "abcd";
int main()
{
    size_t trailLength = strlen(kTrail);
    for (size_t i = 0; i < trailLength; i++) {
        printf("%c\n", kTrail[i]);
        pid_t pid = fork();
        assert(pid >= 0);
    }

    return 0;
}
