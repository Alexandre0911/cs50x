#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size;

    do
    {
        size = get_int("Size: ");
        printf("%i", size);
    }
    while (size < 1);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
