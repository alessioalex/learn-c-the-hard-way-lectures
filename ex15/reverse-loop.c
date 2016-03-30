#include <stdio.h>

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = { 23, 43, 12, 89, 2 };
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    printf("First way:\n\n");
    for (i = count - 1; i >= 0; i--) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
        // printf("&name = %p, &age = %p\n", &names[i], &ages[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    /* int *cur_age = &ages[0]; */
    /* char **cur_name = &names[0]; */

    // second way using pointers
    /* for (i = count - 1; i >= 0; i--) { */
    /*     printf("%s is %d years old.\n", */
    /*             *(cur_name + i), *(cur_age + i)); */
    /*     // printf("&name = %p, &age = %p\n", &cur_name, &cur_age); */
    /* } */

    /* printf("---\n"); */

    // setup the pointers to the end of the arrays
    int *cur_age = &ages[count - 1];
    char **cur_name = &names[count - 1];
    printf("Second way:\n\n");

    // second way using pointers
    for (i = 0; i < count; i++) {
        /* printf("%s\n", *(cur_name - i)); */
        printf("%s is %d years old.\n",
                *(cur_name - i), *(cur_age - i));
    }

    // reset pointers to start of arrays
    cur_age = ages;
    cur_name = names;

    printf("---\n");

    // third way pointers are just arrays
    printf("Third way:\n\n");
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[count - 1 - i], cur_age[count - 1 - i]);
    }

    printf("---\n");

    // forth way with pointers in a stupid complex way
    printf("Forth way:\n\n");
    /* for (cur_name = names, cur_age = ages; */
    /*         (cur_age - ages) < count; cur_name++, cur_age++) { */
    /*     printf("%s has lived %d so far. (%ld)\n", *cur_name, *cur_age, (cur_age - ages)); */
    /* } */


    // https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/BitOp/pointer.html
    // ...
    // The formula used is rather simple. Assume that p1 and p2 are both pointers of type T *. Then, the value computed is:
    // ( p2 - p1 ) == ( addr( p2 ) - addr( p1 ) ) / sizeof( T )

    for (cur_name = names + count - 1, cur_age = ages + count - 1;
            cur_age - ages >= 0; cur_name--, cur_age--) {
        /* printf("%s has lived %d so far. (%ld)\n", *cur_name, *cur_age, (cur_age - ages)); */
        /* printf("%s has lived %d so far. (%ld) %p %p %ld\n", *cur_name, *cur_age, (cur_age - ages), cur_age, ages, sizeof(int)); */
        printf("%s has lived %d so far.\n", *cur_name, *cur_age);
    }

    return 0;
}
