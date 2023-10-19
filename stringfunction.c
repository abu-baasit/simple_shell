#include <stdlib.h>
#include <stddef.h>

/**
 * _strcat -function that concatentes two strings
 * @dest: first string
 * @src:second string
 * Return: return 0 if they are equal
 * or less than or greater 1
 */
char *_strcat(char *dest, char *src)
{
	int k, l;

	k = 0;
	l = 0;

	while (dest[k] != '\0')
		k++;

	while (src[l] != '\0')
	{
		dest[k] = src[l];
		l++;
		k++;
	}

	dest[k] = '\0';

	return (dest);
}

/**
 * _strcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return:return pointer to a string
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcpy - function that returns the number of elements in a string
 * @dest: the resulting string
 * @src: The sourcestring
 * Return: return dest on (Success)
 */

char *_strcpy(char *dest, char *src)
{
	char *initial = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (initial);
}
