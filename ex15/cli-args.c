#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = argc;

    printf("Args in reverse order:\n\n");

    while (i--) {
        printf("%p: %s\n", (argv + i), *(argv + i));
    }

    printf("\n");

    return 0;
}
