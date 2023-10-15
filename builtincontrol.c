#include "shell.h"

/**
* builtinControl - function that takes charge of environmental command
* @av: command line argument
* @env:the environmental variables
* @tokenArray: tokenized user input
* Return:return 1 on (success), otherwise -1
*/

int builtinControl(char *av, char **env, char *tokenArray)
{
	int inspect = -1, k = 0;

	Builtin _cds = {"cd", cdFunction};
	builtin _exits = {"exit", exitFunction};
	Builtin _envs = {"env", envFunction};

	Builtin *builtinPtr[3];

	builtinPtr[0] = &_cds;
	builtinPtr[1] = &_exits;
	builtinPtr[2] = &_envs;

	while (k < 3)
{
	if (strcmp(tokenArray[0], builtinPtr[k]->command) == 0)
{
	builtinPtr[k]->functionCommand(av, env, tokenArray);
	inspect = 1;
	break;
}
	k++;
}
	return (inspect);
}

/**
* exitFunction - Builtin function that stops the ongoing process
* @av: command line argument
* @env: the environmental varaiables
*@tokenArray: tokenized user intake
*/

void exitFunction(char **av, char **env, char **tokenArray)
{
	int status2;

	(void)env;

	if (tokenArray[1] && _strstr(tokenArray[1], "BTIN"))
{
	alert_error(2, 1, av[0], tokenArray[1], "Illegal number: -98");
	freeTokens(tokenArray);
	errno = 2;
	exit(errno);
}
	if (tokenArray[1])
{
	status2 = _atoi(tokenArray[1]);
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
* cdFunction - the builtin  function that determines
* how the current directory is changed
* @av: command line argument
* @env: the environmental variables
* @tokenArray: tokenized user intake
* Return: return void
*/
void cdFunction(char **av, char **env, char **tokenArray)
{
	char *directory = NULL;
	ssize_t size = 0;
	char *oldPwd = getenv("OLPWD");

	(void)env;

	if (tokenArray[1] != NULL)
{
	if (tokenArray[1][0] == '_')
{
	chdir(oldPwd);
}
	else if (chdir(tokenArray[1]) == -1)
{
	alert_error(2, counter, av[0]. "cannot cd", tokenArray[1]);
}
	/*return;*/
}
	if (chdir(getcwd(directory, size)) == -1)
{
	alert_error(2, counter, av[0], "cannot cd" tokenArray[0]);
}
	free(directory);/* memory leak detected*/
}

/**
* envFunction - the builtin function that prints the environmental command.
*@av: command line argument
*@env: the environmental variables
*@tokenArray: tokenized user intake
*/
void envFunction(char **av, char **env, char **tokenArray)
{
	ink k = 0, n = 0;

	(void)av;
	(void)tokenArray;
	while (env[k])
{
	while (env[k][n])
{
	write(1, &env[k][n], 1);
	n++;
}
	n = 0;
	k++;
	write(1, "\n", 1);
}
}
