#include <stdio.h>
// debugging lib, make an assertion and
// fail to standard error fail if expression != 0
#include <assert.h>
// standard library definitions, defines NULL pointer (amongst others)
#include <stdlib.h>
// string operations on null-terminated strings
// for ex. strdup() - string duplicate
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
}
