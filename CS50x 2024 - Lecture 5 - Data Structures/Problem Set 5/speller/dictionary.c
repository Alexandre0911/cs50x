// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int TABLE_SIZE = 26 * 26 * 26;

// Initializing word count
// Will increment when loading instead of going through the array
unsigned int word_count = 0;

// Hash table
node *table[TABLE_SIZE];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int bucket = hash(word);
    node *cursor = table[bucket];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    if (strlen(word) == 1)
    {
        return (tolower(word[0]) - 65) % TABLE_SIZE;
    }
    else if (strlen(word) == 2)
    {
        return ((tolower(word[0]) - 65) + (tolower(word[1]) * 26)) % TABLE_SIZE;
    }
    else
    {
        return ((tolower(word[0]) - 65) + (tolower(word[1]) * 26) + (tolower(word[2]) * 26 * 26)) % TABLE_SIZE;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }

    FILE *src = fopen(dictionary, "r");
    if (src == NULL)
    {
        return false;
    }

    char buffer[LENGTH];

    while (fscanf(src, "%s", buffer) != EOF)
    {
        node *src_word = malloc(sizeof(node));
        int bucket = hash(buffer);

        // printf("[LOAD] -> %s\n", buffer);

        strcpy(src_word->word, buffer);
        src_word->next = table[bucket];
        table[bucket] = src_word;

        word_count++;
    }

    fclose(src);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        node *tmp = table[i];
        node *cursor = table[i];

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
