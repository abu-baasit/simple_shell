#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

/**
 * _strcmp - function which compares two strings
 * @s1: first string
 * @s2: second string
 * Return: return 0 if they are equal or less than or greater than 1
 **/

int _strcmp(char *s1, char *s2)
{
	while (*s1 ==  *s2)
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
 * _strcat - function that concatenates two strings
 * @dest: first string
 * @src: second string to add
 * Return: returns a pointer to a string
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
		k++;
		l++;
	}

	dest[k] = '\0';
	return (dest);
}

/**
 ** _strcpy - This function returns the number of elements in a string
 *@dest: The resulting element
 *@src: The source element
 *Return: dest (success)
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
