#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    /* while (i < 25) { */
    /*     printf("%d\n", i); */
    /*     i++; */
    /* } */
    while (++i) {
        printf("%d\n", i);

        if (i == 25) {
            i = -1;
            // break;
        }
    }

    return 0;
}
