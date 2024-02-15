#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initializing variables
    int change = 0;
    int coins[] = {25, 10, 5, 1};
    int coin_count = 0;
    int i = 0;

    // Ask for an integer while none that's valid is given
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 1);

    // Variable remainder should be initialized equal to the given value of change owed
    int remainder = change;

    // Loop that ends whenever reminder gets to 0
    while (remainder != 0)
    {
        // If remainder (i.e remainder is 70) - coins[i] (i.e. coins[i] is 25) > 0
        // Then the value of coins[i] will be subtracted from the remainder
        // After this, coin_count will be incremented by 1 for every run of the loop where remainder - coins[i] > 0
        if (remainder - coins[i] >= 0)
        {
            remainder -= coins[i];
            coin_count++;
        }
        // If remainder - coins[i] < 0
        // Then the remainder and the coin_count variables will remain untouched
        // And the variable i will be incremented by 1 so the next coin value can be tested
        else
        {
            i++;
        }
    }

    // Finally, when the remainder is 0, print number of coins given as change
    printf("%i\n", coin_count);
}
