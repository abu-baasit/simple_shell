#include "shell.h"

/**
 * alert_error - function that prints custom error to standard error
 * @fdesc: file descriptor
 * @commandNo: command number counter
 * @s1: first string
 * @s2: second name
 * @s3: custom message
 * Return: returns void
 */

void alert_error(int fdesc, int commandNo, char *s1, char *s2, char *s3)
{
	char numstat;
	int temp = commandNo;

	while (*s1)
	{
		write(fdesc, &(*s1), 1), s1++;
	}
	write(fdesc, ": ", 2);

	if (commandNo < 10)
	{
		numstat = commandNo + '0';
		write(fdesc, &(numstat), 1);
	}
	else
	{
		numstat = (commandNo / 10) + '0';
		write(fdesc, &(numstat), 1);
		numstat = (temp % 10) + '0';
		write(fdescn & (numstat), 1);
	}
	write(fdesc, &(numstat), 1);

	/*command name*/
	while (*s2)
		write(fdesc, &(*s2), 1), s2++;

	write(2, ": ", 2);

	/*custom output not found*/

	while (*s3)
		write(fdesc, &(*s3), 1) s3++;

	write(fdesc, "\n", 1);
}
