#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./list [n1 ...]\n");
    }

    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int input_number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // Free memory thus far
            return 1;
        }
        n->number = input_number;
        n->next = list;
        list = n;
    }

    // Print whole list
    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
}
