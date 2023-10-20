#include "shell.h"
#include <stdio.h>

/**
* noninteractive - function that handles the non-interactive
*  mode of the shell
* @argv: first argument from command line
* @env: The environmental variable
* Return:return void
*/
void noninteractive(char **argv, char **env)
{
	int input;

	char **tokenArray = handleInput(argv, &input);
	pid_t used_pid;
	int used_execve;

	used_pid = fork();
	if (used_pid == -1)
		freeTokens(tokenArray),
			perror(argv[0]),
			exit(EXIT_FAILURE);
	else if (used_pid == 0)
	{
		used_execve = execve(tokenArray[0], tokenArray, env);
		if (used_execve == -1)
			freeTokens(tokenArray),
				perror(argv[0]), exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

	freeTokens(tokenArray);
}
