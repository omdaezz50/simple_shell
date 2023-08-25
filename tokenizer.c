#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int var, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (var = 0; str[var] != '\0'; var++)
		if (!is_delim(str[var], d) && (is_delim(str[var + 1], d) || !str[var + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (var = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[var], d))
			var++;
		k = 0;
		while (!is_delim(str[var + k], d) && str[var + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[var++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int var1, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (var1 = 0; str[var1] != '\0'; var1++)
		if ((str[var1] != d && str[var1 + 1] == d) ||
		    (str[var1] != d && !str[var1 + 1]) || str[var1 + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (var1 = 0, j = 0; j < numwords; j++)
	{
		while (str[var1] == d && str[var1] != d)
			var1++;
		k = 0;
		while (str[var1 + k] != d && str[var1 + k] && str[var1 + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[var1++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
