#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 1) {
        printf("You only no arguments. You suck.\n");
    } else if (argc > 1 && argc < 5) {
        printf("You have %d arguments:\n", argc - 1);

        for (i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("You have too many arguments. You suck.\n");
    }

    return 0;
}
