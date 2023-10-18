#include "shell.h"

/**
* handle_signal - A function that  handles the signal base on user input
* @signalnumber:the number to be returned
* Return: return void
*/
void handle_signal(int signalnumber)
{
	(void)signalnumber;
	write(1, "\n", 1);
	write(1, "$>me", 2);
}
