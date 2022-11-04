#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int main(void)
{
    FILE *stream;
    char line[MAX_LEN], *result;
    stream = fopen("words.txt", "r");
    if (!stream)
    {
        perror("Failed to open file.");
    }
    else
    {
        printf("Opened words.txt...\n");

        if ((result = fgets(line, MAX_LEN, stream)) != NULL)
        {
            printf("The string is %s\n", result);
        }
        if (fclose(stream))
        {
            perror("fclose error");
        }
    }

    return EXIT_SUCCESS;
}