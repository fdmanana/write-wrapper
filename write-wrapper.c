#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dlfcn.h>

ssize_t write(int fd, const void *buf, size_t count)
{
    static ssize_t (*real_write)(int, const void *, size_t) = NULL;
    static int counter = 1;
    char prefix[100];
    void *buf2;
    size_t len;
    ssize_t ret;

    if (real_write == NULL) {
        dlerror();
        if ((real_write = dlsym(RTLD_NEXT, "write")) == NULL) {
            char *error = dlerror();
            if (error != NULL) {
                fprintf(stderr, "dlsym error: %s\n", error);
            } else {
                fprintf(stderr, "dlsym error\n");
            }
            exit(EXIT_FAILURE);
        }
    }

    assert(sprintf(prefix, "write #%d: ", counter++) > 0);
    len = strlen(prefix);
    buf2 = (void *) malloc(len + count);
    assert(buf2 != NULL);
    memcpy(buf2, prefix, len);
    memcpy(buf2 + len, buf, count);
    ret = (*real_write)(fd, buf2, len + count);
    free(buf2);

    return ret;
}
