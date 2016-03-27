#include <stdio.h>
/* #include <ctype.h> // for toupper and tolower use */

char to_upper_case(char letter)
{
    if ('A' <= letter && letter <= 'Z') {
        return letter;
    } else {
        return ('A' - 'a' + letter);
    }
}

char to_lower_case(char letter)
{
    if ('a' <= letter && letter <= 'z') {
        return letter;
    } else {
        return ('a' - 'A' + letter);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("ERROR: You need at least one argument.\n");
        // this is how you abort a program
        return 1;
    }

    printf("Number of arguments: %d\n\n", argc);

    int i = 0;
    int j = 0;

    for (j = 1; j < argc; j++) {
        printf("argument #%d: %s\n\n", j, argv[j]);

        char letter = '\0';

        for (i = 0; argv[j][i] != '\0'; letter = argv[j][i], i++) {
            /* char letter = argv[j][i]; */
            /* char letter = toupper(argv[j][i]); */
            char letter = to_upper_case(argv[j][i]);

            switch (letter) {
                case 'a':
                case 'A':
                    printf("%d: 'A'\n", i);
                    break;

                case 'e':
                case 'E':
                    printf("%d: 'E'\n", i);
                    break;

                case 'i':
                case 'I':
                    printf("%d: 'I'\n", i);
                    break;

                case 'o':
                case 'O':
                    printf("%d: 'O'\n", i);
                    break;

                case 'u':
                case 'U':
                    printf("%d: 'U'\n", i);
                    break;

                case 'y':
                case 'Y':
                    if (i > 2) {
                        // it's only sometimes Y
                        printf("%d: 'Y'\n", i);
                    }
                    break;

                default:
                    if ('A' <= letter && letter <= 'Z') {
                        printf("%d: '%c' is not a vowel\n", i, letter);
                    } else {
                        printf("%d: '%c' ignored character\n", i, argv[j][i]);
                    }
            }
        }

        printf("\n");
    }

    return 0;
}
