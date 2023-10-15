#include "shell.h"
#include <stdlib.h>

/**
* getPath - Function that handles path from the environmental variables
* @env:The Environmental variable
* Returns:returns pointer to the path
*/

char *getPath(char **env)
{
	char *main_path = NULL;
	int k = 0;

	while (env[k])
{
	if (_strstr(env[k], "PATH") && env[k][0] == 'P' && env[k][4] == '=')
{
	main_path = env[k];
	break;
}
	k++;
}
	if (main_path != NULL)
{
	for (k = 0; k < 6; k++)
		main_path++;
}
	return (main_path);
}
