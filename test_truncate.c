#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define MAX_LEN 100

/* Truncates a given wordlist, excluding entries that are longer than a given wordlength.
   Creates a new file containing the truncated wordlist.
   Original wordlist file is opened and closed outside of this function. */
void truncWdlist(FILE *wordlist)
{
    regex_t pattern;
    regcomp(&pattern, "^([a-zA-Z]){6}(?![a-zA-Z]).*$", 0);
    char word[MAX_LEN];

    FILE *tr_wrdlist = fopen("words-truncated.txt", "a");
    if (tr_wrdlist == NULL)
    {
        printf("Cannot create file \"words-truncated.txt\".");
    }

    while (fgets(word, MAX_LEN, wordlist))
    {
        printf("%s", word);
        int regex_val = regexec(&pattern, word, 0, NULL, 0);
        printf("%d\n", regex_val);

        if (regexec(&pattern, word, 0, NULL, 0) == 0) /* Problem: regexec() only matches to NULL-ended string */
        {
            printf("match\n");
            fwrite(word, 1, sizeof(word), tr_wrdlist); /* Originally fprintf()*/
        }
    }

    if (fclose(tr_wrdlist) == EOF)
    {
        perror("fclose error");
    }
}

int main()
{
    char word[MAX_LEN];
    // char match_array[MAX_LEN][512000];
    // int arr_size = sizeof(match_array) / sizeof(char *);
    FILE *stream = fopen("words.txt", "r");

    if (!stream)
    {
        perror("Failed to open file.");
    }
    else
    {
        printf("Opened words.txt...\n");

        while (fgets(word, MAX_LEN, stream))
        {
            if (strlen(word) == 7)
            {
                printf("%s", word);
            }
        }

        if (fclose(stream) == EOF)
        {
            perror("fclose error");
        }
        printf("Closed words.txt...");
    }

    return EXIT_SUCCESS;
}