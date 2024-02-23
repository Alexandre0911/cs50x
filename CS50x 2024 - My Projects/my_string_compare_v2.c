#include <stdio.h>

int string_compare(const char *alpha,const char *beta);
int string_length(const char *gamma);

int main(int argc, char *argv[])
{
    // Check If There's 2 Command-Line Arguments
    // If There Are, Print If String Match Or Not
    if (argc < 3)
    {
        printf("Insufficient Arguments. 2 Arguments Should Be Given.\n");
        return 1;
    }
    else if (argc > 3)
    {
        printf("Too Many Arguments. 2 Arguments Should Be Given.\n");
        return 2;
    }
    else
    {
        printf("%i\n", string_compare(argv[1], argv[2]));
        return 0;
    }
}

// Calculate Length Of Given String
int string_length(const char *gamma)
{
    int length = 0;

    while (gamma[length] != '\0')
    {
        length++;
    }

    return length;
}

// Compare 2 Given Strings
int string_compare(const char *alpha, const char *beta)
{
    int correctChars = 0;

    // If String Length Does Not Match, Neither Do The Given Strings
    if (string_length(alpha) != string_length(beta))
    {
        printf("\nString Do Not Match.\n");
        return 5;
    }
    else
    {
        int len = string_length(alpha);

        // If Lengths Match, Check If All Chars Are The Same
        // If Chars In The Same Index Match, Increment correctChars By 1
        for (int i = 0; i < len; i++)
        {
            if (alpha[i] == beta[i])
            {
                correctChars++;
            }
        }

        // If Number Of Correct Chars Equals Length Of Given Strings
        // Then The Strings Match
        if (correctChars == len)
        {
            printf("\nStrings Match.\n");
            return 0;
        }
        else
        {
            printf("\nString Do Not Match.\n");
            return 5;
        }
    }
}