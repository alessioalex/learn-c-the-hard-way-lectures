#include <stdio.h>

/* Warning: This program is wrong on purpose. */

int main(int argc, char *argv[])
{
    int age = 10;
    int height;

    printf("I am %s years old.\n", argc); // this will break
    printf("I am %d inches tall.\n", height);

    return 0;
}
