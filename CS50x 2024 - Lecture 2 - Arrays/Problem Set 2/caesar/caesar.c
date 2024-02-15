#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(string text);
void rotate(string text, int key);

int main(int argc, string argv[])
{
    if (argc == 2 && only_digits(argv[1]))
    {
        // Initializing variables
        // % 26 is used as there are only 26 letters in the american alphabet
        // If the key was 52 instead of 26, the result would be the same
        // But we would have to calculate 26 two times which would equal 0 anyways
        int key = atoi(argv[1]) % 26;
        string plaintext = get_string("plaintext: ");

        // Print ciphertext
        printf("ciphertext: ");
        rotate(plaintext, key);
        printf("\n");

        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }
}

int only_digits(string text)
{
    // Initializing variables needed
    // Initializing len here as I will compare the number of digits present in the text
    // If, after the loop, digits == len, then there's only digits in the text
    int digits = 0;
    int len = strlen(text);

    // Loop through every character in text
    for (int i = 0; i < len; i++)
    {
        // If the ascii values are between 48 and 57 (inclusive)
        // Increment digits by 1 as this means the character analysed is a digit
        if (isdigit(text[i]))
        {
            digits++;
        }
    }

    // Return either true or false based on if digits == len
    return digits == len;
}

void rotate(string text, int key)
{
    // Loop through every character in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Check if character is in the american alphabet
        if (!isalpha(text[i]))
        {
            // If it isn't, print the character (we dont want to rotate a "," [COMMA] or a "." [DOT], for example)
            printf("%c", text[i]);
        }
        else
        {
            // If it is, check if it's ascii value is bigger than 122 ("z")
            if (text[i] + key > 122)
            {
                // If the value is bigger than 122, subtract 26 (i.e. 126 - 26 = 100 -> 100 = "d")
                printf("%c", text[i] + key - 26);
            }
            else
            {
                // If the value is smaller than 122, just print the character itself
                printf("%c", text[i] + key);
            }
        }
    }
}
