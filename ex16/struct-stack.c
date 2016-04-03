#include <stdio.h>
// debugging lib, make an assertion and
// fail to standard error fail if expression != 0
#include <assert.h>
// standard library definitions, defines NULL pointer (amongst others)
#include <stdlib.h>
// string operations on null-terminated strings
// for ex. strdup() - string duplicate
/* #include <string.h> */

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person Person_create(char *name, int age, int height, int weight)
{
    struct Person who;

    int i = 0;
    char c = ' ';

    while (c != '\0') {
        c = name[i];
        who.name[i] = c;
        i++;
    }

    who.age = age;
    who.height = height;
    who.weight = weight;

    return who;
}

void Person_print(struct Person who)
{
    printf("Name: %s\n", who.name);
    printf("\tAge: %d\n", who.age);
    printf("\tHeight: %d\n", who.height);
    printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
    /* struct Person joe; */

    /* joe.name = "Joe Allan"; */
    /* joe.age = 20; */
    /* joe.height = 40; */
    /* joe.weight = 60; */

    struct Person joe = Person_create("Joe Allan", 20, 40, 60);

    Person_print(joe);

    return 0;
}
