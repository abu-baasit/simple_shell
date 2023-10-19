#include <stddef.h>
#include <stdlib.h>

/**
 * _strstr -function that helps to locates a substring
 * @searchString:the string to be searched
 * @mainString: substring in question
 * Return: pointer to the substring or NUll if missing
 */
char *_strstr(char *searchString, char *mainString)
{
	int k, l;

	for (k = 0; searchString[k] != '\0'; k++)
	{
		for (l = 0; mainString[l] != '\0'; l++)
		{
			if (searchString[k + l] != mainString[l])
				break;
		}
		if (!mainString[l])
			return (&searchString[k]);
	}
	return (NULL);
}

/**
 * _strlen -Function that helps to locate a substring
 * @s:argument string
 * Return: Always  (Success)
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
 * _strdup -Function that copies the string.
 * @str: duplicate string
 * Return: return (success) otherwise NULL
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

	duplicate = malloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
		return (NULL);

	while ((duplicate[k] = str[k]) != '\0')
		k++;

	return (duplicate);
}
