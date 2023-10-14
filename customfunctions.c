#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _strdup - A function which copy the string
 * @str: duplicate string
 * Return: return (success) or NULL(error)
 */

char *_strdup(char *str)
{
	char *duplicate;
	unsigned int k, len;

	k = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	deplicate = malloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
		return (NULL);

	while ((duplicate[k] = str[k]) != '\0')
		k++;
	return (duplicate);
}

/**
 * _strlen - function which returns the number of element in s string
 * @s argument string
 * Return: Always (success)
 */

int _strlen(char *s)
{
	int length = 0;
	int k;

	for (k = 0; s[k] != '\0'; k++)
	{
		length += 1;
	}

	return (length);

}

/**
 * _strstr - function that helps to locate a substribg
 * @searchstring: string to be searched
 * @mainstring: the sunstring in question
 * Return: Return pointer to substring or NULL if missing
 */
char *_strstr(char *searchstring, char *mainstring)
{
	int m, n;

	for (m = 0, searchstring[m] != '\0'; m++)

	{

		for (n = 0; mainstring[n] != '\0'; n++)

		{
			if (searchstring[m + n] != mainstring[n])
				break;
		}
		if (!mainstring[n])
			return (&searchstring[m]);
	}
	return (NULL);
}
