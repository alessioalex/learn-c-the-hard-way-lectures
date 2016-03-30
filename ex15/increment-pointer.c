#include <stdio.h>

void print_em(int *age, int count);

int main(int argc, char *argv[])
{
    int age[] = { 10, 12, 33, 45 };

    print_em(&age[1], 2);

    return 0;
}

// http://stackoverflow.com/questions/10150428/pointer-increment-and-dereference-lvalue-required-error
// "You cannot increment an array, but you can increment a pointer. If you convert the array you declare to a pointer, you will get it to work"
void print_em(int *age, int count)
{
    int i = 0;

    for (i = 0; i <= count; i++) {
        /* printf("%d (%p): %d\n", i, &age[i], age[i]); */
        printf("%d (%p): %d\n", i, &age, *age);
        age++;
    }
}
