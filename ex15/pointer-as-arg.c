#include <stdio.h>

void print_em(int *age, int count);

int main(int argc, char *argv[])
{
    int age[] = { 10, 12, 33, 45 };

    print_em(&age[1], 2);

    return 0;
}

void print_em(int *age, int count)
{
    int i = 0;

    for (i = 0; i <= count; i++) {
        printf("%d (%p): %d\n", i, &age[i], age[i]);
    }
}
