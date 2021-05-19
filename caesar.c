#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool check_valid_key(string s);

int main(int argc, string argv[])
{
    if(argc != 2 || !check_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    //once I check for correct argv put key into an int k
    int k = atoi(argv[1]);

    // check if the integer is non-negative
    // if (k < 0)
    // {
    //     printf("Nope\n");
    //     return 1;
    // }
    // else
        // prompt user for a code to encrypt
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                char c = plaintext[i];
                //check if the letter is uppercase or lowercase then convert
                if (isalpha(c) && islower(c))
                    printf("%c", (((c + k) - 97) % 26) + 97);
                else if (isalpha(c) && isupper(c))
                    printf("%c", (((c + k) - 65) % 26) + 65);
                //if neither then just print whatever it is
                else
                    printf("%c", c);
            }
            printf("\n");
            return 0;
    }

bool check_valid_key(string s)
    {
      for (int i = 0, n = strlen(s); i < n; i++)
       if (isdigit(s[i]))
           return true;
      return false;
    }







