#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage ./recover FILE\n");
    }

    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("Invalid File\n");
        return 1;
    }

    FILE *img = NULL;

    BYTE buffer[BLOCK_SIZE];
    char filename[8];
    int count = 0;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count == 0)
            {
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);

                count++;
            }
            else if (count > 0)
            {
                fclose(img);

                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);

                count++;
            }
        }
        else if (count > 0)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    fclose(img);
    fclose(card);
}
