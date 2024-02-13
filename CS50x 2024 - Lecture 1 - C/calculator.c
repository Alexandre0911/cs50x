#include <stdio.h>
#include <cs50.h>

int add(int x, int y);
int multiply(int x, int y);
int subtract(int x, int y);
float divide(int x, int y);

int main(void)
{
    int mode;

    do
    {
        mode = get_int("\n[1] - Add\n[2] - Multiply\n[3] - Subtract\n[4] - Divide\n\n>>> ");
        if (mode < 1 || mode > 4)
        {
            printf("[%i] Does not exist.\n", mode);
        }
    }
    while (mode < 1 || mode > 4);

    int x = get_int("x: ");
    int y = get_int("y: ");

    if (mode == 1)
    {
        printf("%i + %i = %i\n", x, y, add(x, y));
    }
    else if (mode == 2)
    {
        printf("%i * %i = %i\n", x, y, multiply(x, y));
    }
    else if (mode == 3)
    {
        printf("%i - %i = %i\n", x, y, subtract(x, y));
    }
    else if (mode == 4)
    {
        printf("%i / %i = %.25f\n", x, y, divide(x, y));
    }
}

int add(int x, int y)
{
    return x + y;
}

int multiply(int x, int y)
{
    return x * y;
}

int subtract(int x, int y)
{
    return x - y;
}

float divide(int x, int y)
{
    return (float) x / (float) y;
}
