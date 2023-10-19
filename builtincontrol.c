#include "shell.h"

/**
* builtinControl - function that takes charge of environmental command
* @argv: command line argument
* @env:the environmental variables
* @tokenArray: tokenized user input
* Return:return 1 on (success), otherwise -1
*/
int builtinControl(char **argv, char **env, char **tokenArray)
{
	int inspect = -1, k = 0;

	Builtin cd_s = {"cd", cdFunction};
	Builtin exit_s = {"exit", exitFunction};
	Builtin env_s = {"env", envFunction};

	Builtin *builtinPtr[3];

	builtinPtr[0] = &cd_s;
	builtinPtr[1] = &exit_s;
	builtinPtr[2] = &env_s;

	while (k < 3)
	{
		if (_strcmp(tokenArray[0], builtinPtr[k]->command) == 0)
		{
			builtinPtr[k]->functionCommand(argv, env, tokenArray);
			inspect = 1;
			break;
		}
		k++;
	}

	return (inspect);
}

/**
 * exitFunction - Builtin function that stops the ongoing process
 * @argv:command line argument
 * @env: Environmental variables
 * @tokenArray: tokenized user intake
 */

void exitFunction(char **argv, char **env, char **tokenArray)
{
	int status2;

	(void)env;

	if (tokenArray[1] && _strstr(tokenArray[1], "HBTN"))
	{
		alert_error(2, 1, argv[0], tokenArray[0], "Illegal number: HBTN");
		freeTokens(tokenArray);
		errno = 2;
		exit(errno);
	}
	if (tokenArray[1] && _strstr(tokenArray[1], "-98"))
	{
		alert_error(2, 1, argv[0], tokenArray[0], "Illegal number: -98");
		freeTokens(tokenArray);
		errno = 2;
		exit(errno);
	}
	if (tokenArray[1])
	{
		status2 = atoi(tokenArray[1]);
		freeTokens(tokenArray);
		errno = status2;
		exit(errno);
	}
	if (errno != 0)
	{
		freeTokens(tokenArray);
		exit(2);
	}
	freeTokens(tokenArray);
	exit(errno);
}

/**
 * cdFunction -The builtin function that changes current directory
 * @argv: command line argument
 * @env: The Environmental variables
 * @tokenArray:tokenized user intake
 */

void cdFunction(char **argv, char **env, char **tokenArray)
{
	char *directory = NULL;
	size_t size = 0;
	char *oldPwd = getenv("OLDPWD");

	(void)env;

	if (tokenArray[1] != NULL)
	{
		if (tokenArray[1][0] == '-')
		{
			chdir(oldPwd);
		}
		else if (chdir(tokenArray[1]) == -1)
		{
			alert_error(2, counter, argv[0], "can't cd to", tokenArray[1]);
		}
		return;
	}
	if (chdir(getcwd(directory, size)) == -1)
	{
		alert_error(2, counter, argv[0], "can't cd to", tokenArray[0]);
	}
	free(directory); /* memory leak detected*/
}

/**
 * envFunction -The  builtin function that
   prints the environment command
 * @argv: Argument vector from command line
 * @env: Environment variables
 * @tokenArray:tokenized user intake
 */

void envFunction(char **argv, char **env, char **tokenArray)
{
	int k = 0, l = 0;

	(void)argv;
	(void)tokenArray;

	while (env[k])
	{
		while (env[k][l])
		{
			write(1, &env[k][l], 1);
			l++;
		}
		l = 0;
		k++;
		write(1, "\n", 1);
	}
}
