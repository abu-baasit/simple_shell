#include "shell.h"
#include <stddef.h>
#include <stdlib.h>

/**
* _strdup - Function that copy the string
* @str: duplicate the string
* Return: return (success) or NUll if error encountered
*/
char _strdup(char *str)
{
	char *duplicate;
	unsigned int k, len;

	k = 0;
	len = 0;

	if (str == NULL)
	return (NULL);

	while (str[len])
		len++;

	duplicate = maloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
		return (NULL);

	while ((duplicate[k] = str[k]) != '\0')
		k++
			return (duplicate);
}

/**
* _strstr - Function that helps to locate a substring
* @searchString: string to be searched
* @mainString: the substring in question
* Return: return pointer to substring or NULL if missing
*/

char *_strstr(char *searchString, char *mainString)
{
	int m, n;

	for     (m = 0; searchString[m] != '\0'; m++)
{
	for (n = 0; mainString[n] != '0\'; n++)
{
	if (searchString[m + n] != mainString[n])

	break;
}
	if (!mainString[n])
	return (&searchString[m]);
}
	return (NULL)'
}

/**
* _strlen - function that returns the number in a string
* @s: The string argument
* Return: Always (success)
*/
int _strlen(char *s)
{
	int lenght = 0;
	int k;

	for (k = 0; s[k] != '\0', k++)
{
	lenght += 1;
}
return (lenght);
}
