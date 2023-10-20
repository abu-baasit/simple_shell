#include "shell.h"

/**
 * interactnControl - A function that controls the interactive mode
 * @argv: command line argument
 * @counter: command line counter
 * @input: interactive mode
 * @env: environment variable
 * Return: void
 */
void interactnControl(char **argv, char **env, int *counter, int *input)
{
	char **tokenArray = handleInput(argv, input), *inPath = NULL;

	if (tokenArray[0] == NULL || tokenArray == NULL)
	{
		free(tokenArray[0]), freeTokens(tokenArray);
		return;
	}
	if (builtinControl(argv, env, tokenArray) == 1)
	{
		freeTokens(tokenArray);
		return;
	}
	/*controls the path for command that is run*/
	if (lostPathControl(inPath, tokenArray, env,
							  input, counter, argv) == 1)
		return;
	/*Handling PATH for command run*/
	if (access(tokenArray[0], F_OK) == -1)
	{
		if (controlPath(argv, env, tokenArray, counter) == -1)
		{
			alert_error(2, *counter, argv[0], tokenArray[0], "not found");
			freeTokens(tokenArray);
			if (*input != 1)
				exit(127);

			errno = 127;
			return; /*Error Status for when path not found*/
		}
		freeTokens(tokenArray);
		return;
	}
	/* Handling absolute path or relative path*/
	fullPathControl(tokenArray, env, argv, *input);
}

/**
 * fullPathControl -Function that target when the other path fails
 * @tokenArray: tokenized user input
 * @env: Environmental variables
 * @argv:command line arguments
 * @input: interactive mode
 * Return:return void
 */
void fullPathControl(char **tokenArray, char **env, char **argv, int input)

{
	pid_t used_pid;
	int used_execve;

	(void)input;
	used_pid = fork();

	if (used_pid == -1)
		freeTokens(tokenArray), perror(argv[0]),
			exit(EXIT_FAILURE);
	else if (used_pid == 0)
	{
		used_execve = execve(tokenArray[0], tokrnArray, env);
		if (used_execve == -1)
			freeTokens(tokenArray),
				perror(argv[0]), exit(EXIT_FAILURE);
		/*Error status for when execve fails*/
	}
	else
	{
		wait(&status), freeTokens(tokenArray);
		errno = status;
	}
}

/**
 * lostPathControl -function that handles special cases
 * @inPath: Check the command status
 * @tokenArray: tokenized user input
 * @env: Environment variables
 * @input: Mode of interaction
 * @counter: Command line counter
 * @argv: command line argument
 * Return: return void
 */
int lostPathControl(char *inPath, char **tokenArray,
						  char **env, int *input, int *counter, char **argv)
{
	inPath = findStringPath(tokenArray[0], getPath(env));
	if (tokenArray[0][0] != '/' && tokenArray[0][0] != '.' &&
		tokenArray[1] == NULL &&
		access(tokenArray[0], F_OK) != -1 && inPath == NULL)
	{
		alert_error(2, *counter, argv[0], tokenArray[0], "not found");
		freeTokens(tokenArray);
		if (*input != 1)
			exit(127);
		errno = 127; /*Error Status for when path not found*/
		return (1);	 /*Return for check in main function*/
	}
	else
		return (2);
}
