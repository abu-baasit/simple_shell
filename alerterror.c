#include "shell.h"

/**
 * alert_error - function that prints custom error to standard error
 * @fd: file descriptor
 * @commandNo: command number counter
 * @s1: first string
 * @s2: second name
 * @s3: custom message
 * Return: returns void
 */
void alert_error(int fd, int commandNo, char *s1, char *s2, char *s3)
{
	char numstat;
	int temp = commandNo;

	while (*s1)
	{
		write(fd, &(*s1), 1), s1++;
	}
	write(fd, ": ", 2);

	if (commandNo < 10)
	{
		numstat = commandNo + '0';
		write(fd, &(numstat), 1);
	}
	else
	{
		numstat = (commandNo / 10) + '0';
		write(fd, &(numstat), 1);
		numstat = (temp % 10) + '0';

		write(fd, &(numstat), 1);
		write(fd, &(numstat), 1);
	}
	write(fd, ": ", 2);

	/*command name*/
	while (*s2)
		write(fd, &(*s2), 1), s2++;

	write(2, ": ", 2);

	/* custom output not found*/
	while (*s3)
		write(fd, &(*s3), 1), s3++;

	write(fd, "\n", 1);
}
