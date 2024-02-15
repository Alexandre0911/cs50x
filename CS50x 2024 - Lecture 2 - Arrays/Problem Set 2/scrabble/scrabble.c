#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function Prototype
int get_score(string word);

int main(void)
{
    // Getting players' words
    string player_one_word = get_string("Player 1: ");
    string player_two_word = get_string("Player 2: ");

    // Getting players's score
    int player_one_score = get_score(player_one_word);
    int player_two_score = get_score(player_two_word);

    // Compare results and decide winner
    if (player_one_score > player_two_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_two_score > player_one_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score(string word)
{
    // Initializing array of points for each letter in the english alphabet
    int points_array[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Initializing word_points so we can track each words score
    int word_points = 0;

    // Loop through all characters in the word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // If uppercase character - 65 (ascii value for A) is between 0 and 25 (is a letter in the alphabet, as there are only 26)
        // This is used to exclued punctuation
        if (toupper(word[i]) - 65 >= 0 && toupper(word[i]) - 65 <= 25)
        {
            // i.e. -> A - 65 = 0 -> points_array[0] = 1 point
            // word_points += 1
            word_points += points_array[toupper(word[i]) - 65];
        }
    }

    // Return word points
    return word_points;
}
