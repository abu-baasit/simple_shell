#include "shell.h"

/**
* _isdigit - Function that checks for a digit from 0 to 9 precisely.
* @c: A variable and a parameter in the function checked
* Return: return 1 if its a digit and 0 if otherwise.
*/

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
{
	return (1);
}
	else
{
	return (0);
}
}
