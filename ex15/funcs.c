#include <stdio.h>

void print_by_indexing(int count, int ages[], char *names[]);
void print_with_pointers(int count, int *cur_age, char **cur_name);

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = { 23, 43, 12, 89, 2 };
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    int count = sizeof(ages) / sizeof(int);

    print_by_indexing(count, ages, names);

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    print_with_pointers(count, cur_age, cur_name);

    return 0;
}

void print_by_indexing(int count, int ages[], char *names[])
{
    // safely get the size of ages
    int i = 0;

    // first way using indexing
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    // warning: sizeof on array function parameter will return size of 'int *' instead of 'int []'
    // No-no ==> int count = sizeof(ages);

    printf("---\n");
}

void print_with_pointers(int count, int *cur_age, char **cur_name)
{
    int i = 0;

    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
                *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");
}
