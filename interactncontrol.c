#include "shell.h"
/**
 * _interactnControl - A feunction that controls the interactive mode
 * @av: command line argument
 * @counter: command line counter
 * @input: interactive mode
 * @env: environment variable
 * eturn: void
 */
void _interactnControl(char **av, int *counter, char **env, int *input)
{
	char **tokenArray = handleInput(av, input), *inpath = NULL;

	if (tokenArray[0] == NULL || tokenArray == NULL)

	{
		free(tokenArray[0]), freeTokens(tokenArray);
		return;
	}
	if (builtinControl(av, env, tokenArray) == 1)
	{
		freeTokens(tokenArray);
		return;
	}
	/* controls the path that is missing*/
	if (lostPathControl(inPath, tokenArray, env, input, counter, av) == 1)
		return;
	/* controls the path for command that is run*/
	if (access(tokenArray[0], F_OK) == -1)
	{
		if (controlPath(av, env, tokenArray, counter) == -1)
		{
			alert_error(2, *counter, av[0], tokenArray[0]. "not found");
			freeTokens(tokenArray);
			if (*input != 1)
				exit(127);
			errno = 127;
			return; /*Error status when path not found*/
		}
		freeTokens(tokens(Array);
				return;
	}
	/*handling absolute path*/
	fullPathControl(tokenArray, env, av, *input);
}
/**
 * fullPathControl - function that targets when the other path fails
 * @av: command line arguement
 * @env: Environment variables
 * @tokenArray: Array of tokenized user input
 * @input: interactive mode
 * Return: void
 */

void fullPathControl(char **av, char **env, char **tokenArray, int input)
{
	pid_t used_pid;
	int used_execve;

	(void)input;
	used_pid = fork();

	if (used_pid == -1)
		freeTokens(tokenArray), perror(av[0]),
			exit(EXIT_FAILURE);
	else if (used_pid == 0)
	{
		used_execve = execve(tokenArray[0], tokrnArray, env);
		if (used_execve == -1)
			freeTokens(tokenArray),
				perror(av[0]), exit(EXIT_FAILURE);
		/*Error status display when execve fails*/
	}
	else
	{
		wait(&status), freeTokens(tokenArray);
		errno = status;
	}
}

/**
 * lostPathControl - Function that handles special case
 * @av: command line arguement
 * @env: environment variables
 * @tokenArray: array of token of tokenized user input
 * @inPath: check the command status
 * @counter: command line counter
 * @input: interactive mode
 * @return: void
 */

int lostPathControl(char *inPath, char **av, char **tokenArray, char **env,
	int *counter)
{
	inPath = findStringPath(tokenArray[0], getPath(env));
	if (tokenArray[0][0] != '/' && tokenArray[0][0] != '.'
	&& tokenArray[1] == NULL &&
	access(tokenArray[0], F_OK) != -1 && inPath == NULL)
	{
		alert_error(2, *counter, av[0], tokenArray[0], "not found");
		freeTokens(tokenArray);
		if (*input != 1)
			exit(127);
		errno = 127; /*Error Status to display when path not found*/
		return (1); /*Return to check in main function*/
	}
	else
		return (2);
}
