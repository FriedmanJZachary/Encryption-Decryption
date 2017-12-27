#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

    if (argc == 3)
    {
        int key = atoi(argv[1]);
        char *plaintext = argv[2];
        char newtext[strlen(argv[2])];
        printf("\n Key: \n %i \n\n", key);
        printf("Text to be encyphered: ");
        for (int i = 0; i < strlen(argv[2]); i++)
        {
            printf("%c", plaintext[i]);
        }
        printf("\n\n");

        for (int key = 0; key < 26; key++)
        {
            for (int i = 0; i < strlen(argv[2]); i++)
            {
                if (isupper(plaintext[i]))
                {
                int letter = 'A';
                int plainnumber = (int)plaintext[i];
                int new;
                new = (letter + ((key + plainnumber - letter) % 26));
                newtext[i] = (char) new;
                }
                else if (islower(plaintext[i])) {
                int letter = 'a';
                int plainnumber = (int)plaintext[i];
                int new;
                new = (letter + ((key + plainnumber - letter) % 26));
                newtext[i] = (char) new;
                }
                else
                {
                newtext[i] = plaintext[i];
                }

            }

            printf("Scrambled Text: ");

            for(int i = 0; i < strlen(argv[2]); i++)
            {
                printf("%c", newtext[i]);
            }

            printf("\n");
            printf("Key: %i", key);
            printf("\n\n");

        }

    }
    else
    {
        printf("\nERROR: INVALID SUBMISSION\n");
    }

    return 0;
}
