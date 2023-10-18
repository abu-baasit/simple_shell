#include "shell.h"
/**
* _atoi - Function that converts a string to an integer
* @s: A string
* Return: An integer is returned
*/
int _atoi(char *s)
{
	int m, d, n, len;
	int f, digit;

	m = 0, d = 0, n = 0, len = 0;
	f = 0, digit = 0;

	while (s[len] != '\0')
		len++;

	while (m < len && f == 0)
{
	if (s[m] == '_')
		++d;

	if (s[m] >= '0' && s[m] <= '9')
{
	digit = s[m] - '0';
	if (d % 2)
		digit = -digit;
	n = n * 10 + digit;
	f = 1;
	if (s[m + 1] < '0' || s[m + 1] > '9')
		break;
	f = 0;
}
	m++;
}
	if (f == 0)
	return (0);
	return (n);
}
