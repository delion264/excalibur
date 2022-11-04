#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

#define SLOTS 6       /* number of letters in mystery word */
#define POSSLETTERS 8 /* number of possible letters in each slot */
#define MAX_LEN 100   /* maximum word length */
#define WORD_LIST "words.txt"

/* Truncates a given wordlist, excluding entries that are longer than a given wordlength.
   Returns a new file containing the truncated wordlist. */
FILE *trunc_wdlist(FILE *wordlist, int wordlength)
{
    regex_t pattern;
    int regex_val = 0;
    char *pattern_str = snprintf("^([a-zA-Z]){%d}(?![a-zA-Z])", wordlength);
    regex_val = regcomp(&pattern, pattern_str, 0);
    /* regexec through whole wordlist and save to trunc_wdlist.txt */
    // regexec(&pattern, )
}

/* Iterates through a wordlist and checks if a string is a (prefixing) substring of a wordlist entry */
bool isSubstring(FILE *wordlist, char *str)
{
    regex_t pattern;
    int regex_val = 0;
    char word[MAX_LEN];
    char *result;

    regex_val = regcomp(&pattern, str, 0); /* Compile str into a regex pattern */

    if (regex_val == 0)
    {
        while (result = fgets(word, POSSLETTERS + 1, wordlist) != NULL) /* POSSLETTERS+1 used since fgets() includes NULL at end of word */
        {
            regexec(&pattern, word, 0, NULL, 0); /* Check if current wordlist entry matches regex pattern */
        }
    }
    return 1;
}

int main()
{
    FILE *dictionary = fopen(WORD_LIST, "r");
    if (dictionary == NULL)
    {
        printf("No wordlist found.\n");
        return (EXIT_FAILURE);
    }

    char letters[6][8] = {"sfcayrdk",
                          "gmectour",
                          "tlevoxmj",
                          "kgbqhfri",
                          "nzvitupa",
                          "erfwmjln"};

    char curr_wd[6] = {'\0'};
    int slot = 0;
    int curr_letter = 0;
    int next_letter = 0;
    /* int start_letter = 0; */
    *(curr_wd + slot) = letters[slot][next_letter];

    while (slot < SLOTS)
    {
        if (isSubstring(dictionary, curr_wd) != 0)
        {
            slot++;
            *(curr_wd + slot) = letters[slot][next_letter];
            curr_letter = next_letter;
            next_letter = 0;
        }
        else
        {
            next_letter++;
            if (next_letter < POSSLETTERS)
            {
                *(curr_wd + slot) = letters[slot][next_letter];
            }
            else
            {
                *(curr_wd + slot) = '\0';
                slot--;
                curr_letter++;
                *(curr_wd + slot) = letters[slot][curr_letter];
                next_letter = 0;
            }
        }
    }
}