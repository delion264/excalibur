#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define MAX_LEN 100

int main()
{
    FILE *stream;
    char line[MAX_LEN];
    stream = fopen("words.txt", "r");

    if (!stream)
    {
        perror("Failed to open file.");
    }
    else
    {
        printf("Opened words.txt...\n");

        while (fgets(line, MAX_LEN, stream))
        {
            printf("%s", line);
        }

        if (fclose(stream) == EOF)
        {
            perror("fclose error");
        }
    }

    return EXIT_SUCCESS;
}