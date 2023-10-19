#include "shell.h"

/**
* findStringPath -Function that finds if a string exists in the path
* @command: command string to be searched
* @path: Path variable
* Return: return pointer to a string, otherwise NULL.
*/
char *findStringPath(char *command, char *path)
{
	char *result = NULL;

	if (path != NULL)
	result = _strstr(path, command);

	return (result);
}
