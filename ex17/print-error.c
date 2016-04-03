#include <stdio.h>
#include <errno.h>

int main(void)
{
    FILE* f = fopen("non_existent", "r");
    if (f == NULL) {
        printf("errno: %d\n", errno);
        perror("open()");
    } else {
        fclose(f);
    }
}

// $ ./print-error
// errno: 2
// open(): No such file or directory
