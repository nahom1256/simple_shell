#include "nashell.h"

int natoken_len(char *nastr, char *delim);
int nacount_tokens(char *str, char *delim);
char **_nastrtok(char *nline, char *ndelim);

/**
 * nacount_tokens - Counts
 * @str: The string
 * @delim: The delimiter
 *
 * Return: The number of words
 */
int nacount_tokens(char *str, char *delim)
{
        int naindex, natokens = 0, nalen = 0;

        for (naindex = 0; *(str + naindex); naindex++)
                nalen++;

        for (naindex = 0; naindex < nalen; naindex++)
        {
                if (*(str + naindex) != *delim)
                {
                        natokens++;
                        naindex += natoken_len(str + naindex, delim);
                }
        }

        return (natokens);
}

/**
 * natoken_len - Locates the delimiter
 * @str: The string.
 * @delim: The delimiter character.
 *
 * Return: The delimiter index marking the end of
 *         the intitial token pointed to be str.
 */
int natoken_len(char *str, char *delim)
{
	int naindex = 0, nalen = 0;

	while (*(str + naindex) && *(str + naindex) != *delim)
	{
		nalen++;
		naindex++;
	}

	return (nalen);
}

/**
 * _nastrtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter.
 *
 * Return: A pointer to an array containing the tokenized words.
 */
char **_nastrtok(char *line, char *delim)
{
	char **ptr;
	int index = 0, tokens, t, letters, l;

	tokens = count_tokens(line, delim);
	if (tokens == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (tokens + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < tokens; t++)
	{
		while (line[index] == *delim)
			index++;

		letters = token_len(line + index, delim);

		ptr[t] = malloc(sizeof(char) * (letters + 1));
		if (!ptr[t])
		{
			for (index -= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
		{
			ptr[t][l] = line[index];
			index++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
