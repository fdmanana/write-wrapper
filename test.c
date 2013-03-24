#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < argc; ++i) {
        char msg[512];
        size_t len;

        sprintf(msg, "argc[%d] = %s\n", i, argv[i]);
        len = strlen(msg);
        assert(write(STDOUT_FILENO, msg, len) >= len);
    }
    return 0;
}
