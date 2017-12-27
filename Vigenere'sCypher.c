#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

    if (argc == 3)
    {
        //Save inputted text to variables and make array for encyphered text
        char *key = argv[1];
        char *plaintext = argv[2];
        char newtext[strlen(argv[2])];

        int decodei = 0;
        for (int i = 0; i < strlen(argv[2]); i++)
        {

            //set up current key
            decodei %= strlen(argv[1]);
            int currentkey = (int)key[decodei];
            if(isupper(key[decodei]))
            {
                int letter = 'A';
                currentkey -= (int)letter - 1;
            }
            else if(islower(key[decodei]))
            {
                int letter = 'a';
                currentkey -= (int)letter - 1;
            }
            else
            {
                printf("\nERROR: NON-TEXT KEY DETECTED\n");
                printf("KEY: %c", key[decodei]);
            }
            printf("\nCurrent Key: %i", currentkey);

            //Modify text by key, save result in newtext variable
            if (isupper(plaintext[i]))
            {
            int letter = 'A';
            int plainnumber = (int)plaintext[i];
            int new;
            new = (letter + ((currentkey + plainnumber - letter) % 26));
            newtext[i] = (char) new;
            }
            else if (islower(plaintext[i])) {
            int letter = 'a';
            int plainnumber = (int)plaintext[i];
            int new;
            new = (letter + ((currentkey + plainnumber - letter) % 26));
            newtext[i] = (char) new;
            }
            else
            {
            newtext[i] = plaintext[i];
            }

            decodei++;
        }

        printf("\n\nScrambled Text: ");
        for(int i = 0; i < strlen(argv[2]); i++)
        {
            printf("%c", newtext[i]);
        }
        printf("\n");

        printf("Keyword: ");
        for(int i = 0; i < strlen(argv[1]); i++)
        {
            printf("%c", key[i]);
        }
        printf("\n\n");

    }

    else
    {
        printf("./Vigenere'sCypher.c Keyword Text\n");
    }

    return 0;
}
