#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_words(string text);
int count_letters(string text);
int count_sentences(string text);
float calculate_index(int word_count, int letter_count, int sentence_count);

int main(void)
{
    // Getting text input from user
    string text = get_string("Text: ");

    // Initializing required variables
    int word_count = count_words(text);
    int letter_count = count_letters(text);
    int sentence_count = count_sentences(text);
    int index = calculate_index(word_count, letter_count, sentence_count);

    // Checks if index is less than 1
    // If it is, print "Before Grade 1"
    // Else, if it's equal to or greater than 16, print "Grade 16+"
    // Else, print "Grade " with the respective grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_words(string text)
{
    // Initializing word_count to 1 as the last word is not followed by a " " [SPACE],
    // it could be followed by a "." [DOT], a "?" [QUESTION MARK] or a "!" [EXCLAMATION MARK]
    int word_count = 1;

    // Loop through every character in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // If the character is a " " [SPACE], increment word_count by 1 as every word is followed by a " " [SPACE]
        if (text[i] - ' ' == 0)
        {
            word_count++;
        }
    }

    return word_count;
}

int count_letters(string text)
{
    int letter_count = 0;

    // Loop through every character in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // If character is a letter, (uppercase character - 65 should be between 0 and 25 (inclusive))
        // Increment letter_count by 1
        if (toupper(text[i]) - 65 >= 0 && toupper(text[i]) - 65 <= 25)
        {
            letter_count++;
        }
    }

    return letter_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;

    // Loop through every character in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // If character is a "." [DOT], a "!" [EXCLAMATION MARK] or a "?" [QUESTION MARK]
        // Increment sentence_count by 1 as any of this characters mean the end of a sentence
        if (text[i] - '.' == 0 || text[i] - '!' == 0 || text[i] - '?' == 0)
        {
            sentence_count++;
        }
    }

    return sentence_count;
}

float calculate_index(int word_count, int letter_count, int sentence_count)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    // L is the average number of letters per 100 words in the text:
    // that is, the number of letters divided by the number of words, all multiplied by 100.
    // S is the average number of sentences per 100 words in the text:
    // that is, the number of sentences
    // divided by the number of words, all multiplied by 100.

    float L = (float) letter_count / (float) word_count * 100;
    float S = (float) sentence_count / (float) word_count * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}
