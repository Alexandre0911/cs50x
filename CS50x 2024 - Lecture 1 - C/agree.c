#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char answer = get_char("Do You agree? [Y/N] >>> ");

    if (answer == 'y' || answer == 'Y')
    {
        printf("Agreed!\n");
    }
    else if (answer == 'n' || answer == 'N')
    {
        printf("Not Agreed.\n");
    }
}
