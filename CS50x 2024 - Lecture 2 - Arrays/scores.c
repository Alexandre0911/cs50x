#include <stdio.h>
#include <cs50.h>

float average(int length, int scores[]);

int main(void)
{
    const int N = get_int("Number of Scores To Calculate: ");
    int scores[N];

    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score N.%i: ", i+1);
    }

    printf("Score Average: %.2f\n", average(N, scores));
}

float average(int length, int scores[])
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += scores[i];
    }

    return sum / (float) length;
}
