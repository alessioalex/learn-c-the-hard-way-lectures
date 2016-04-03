#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

int main(int argc, char *argv[])
{
    errno = 2;
    printf("MAX_DATA = %d\n", MAX_DATA);
    printf("MAX_ROWS = %d\n", MAX_ROWS);
    printf("errno = %d\n", errno);
    perror("foobar()");
}
