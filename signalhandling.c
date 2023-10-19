#include "shell.h"

/**
* handle_signal - A function that  handles the signal base on user input
* @signum:the number to be returned
* Return: return void
*/
void handle_signal(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	write(1, "$", 2);
}
