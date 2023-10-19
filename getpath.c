#include "shell.h"
#include <stdlib.h>

/**
* getPath - Function that handles path from the environmental variables
* @env:The Environmental variable
* Returns:returns pointer to the path
*/

char *getPath(char **env)
{
	char *path = NULL;
	int k = 0;

	while (env[k])
	{
		if (_strstr(env[k], "PATH") && env[k][0] == 'P' && env[k][4] == '=')
		{
			path = env[k];
			break;
		}
		k++;
	}
	if (path != NULL)
	{
		for (k = 0; k < 6; k++)
			path++;
	}

	return (path);
}
