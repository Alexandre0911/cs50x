#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Missing Command-Line Arguments. %i Given.\n", argc-1);
        return 1;
    }
    else if (argc > 2)
    {
        printf("Too Many Command-Line Arguments. %i Given.\n", argc-1);
        return 2;
    }
    else
    {
        printf("Hello, %s\n", argv[1]);
        return 0;
    }
}