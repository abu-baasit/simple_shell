#include "shell.h"
/**
 * atoi -Function that convert string to an integer
 * @s:converted string
 * Return: return integer
 */
int _atoi(char *s)
{
	int k, d, n, len, f, digit;

	k = 0, d = 0, n = 0, len = 0;
	f = 0, digit = 0;

	while (s[len] != \0')
		len++;

	while (k < len && f == 0)
	{
		if (s[k] == '-')
			++d;

		if (s[k] >= '0' && s[k] <= '9')
		{
			digit = s[k] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[k + 1] < '0' || s[k + 1] > '9')
				break;
			f = 0;
		}
		k++;
	}

	if (f == 0)
		return (0);

	return (n);
}
