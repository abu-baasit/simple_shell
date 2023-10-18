#include "shell.h"

/**
 * controlPath - A function that controls the path
 * when a command name is passed
 * @av: argument passed
 * @tokenArray: argument for command
 * @env: environment variables
 * @counter:counter variable pointer
 * Return: returns ) if successful or -1 if otherwise
 */

int controlPath(char **av, char **tokenArray, char **env, int *counter)
{
	char **arrayPath = pathSplitFunction(getPath(env)), *fullPath;
	int k = 0, len_str, used_execve;
	pid_t used_pid;
	int status = -1;

	(void)counter;
	if (arrayPath == NULL)
		return (-1);

	while (arrayPath[k])
	{
		len_str = _strlen(arrayPath[k]) + _strlen(tokenArray[0]) + 2;
		fullPath = malloc(len_str);
		_strcpy(fullPath, arrayPath[k]);
		_strcat(fullPath, "/");
		_strcat(fullPath, tokenArray[0]);
		if (access(fullPath, F_OK) == -1)
		{
			free(fullPath), k++, errno = 127;
			continue;
		}
		else
		{
			status = 1, used_pid = fork();
			if (used_pid == -1)
				return (-1);
			else if (used_pid == 0)
			{
				used_execve = execve(fullPath, tokenArray, env);
				if (used_execve == -1)
					perror(av[0]), exit(EXIT_FAILURE);
			}
			else
				wait(&status), free(fullPath), errno = status;
			break;
		}
	}
	freeTokens(arrayPath);
	return (status);
}
