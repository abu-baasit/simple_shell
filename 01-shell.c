#include "shell.h"

/**
 *main - A simple shell
 *@ac: The first argument variable
 *@av: The second argument varable
 *@env: an environment variable
 *Return: Always (0) when successful
 */

int main(int ac, char **av, char **env)
{
	int input = 0;

	counter = 1;
	(void)ac;

	if (isatty(0) == 1)
		input = 1;

	errno = 0;

	while (1)
	{
		if (input == 1)
		{
			write(1, "$ ", 2);
		}

		interactnControl(av, env, &counter, &input);
		counter++;
	}
		return (errno);
}

/**
*freeTokens - Function that frees an array of strings
*@arrayTokens: the arguement pointer to be freed
*Return: return void;
*/

void freeTokens(char **arrayTokens)
{
	int k = 0;

	while (arrayTokens[k] != NULL)
	{
		free(arrayTokens[k]);
		k++;
	}
	free(arrayTokens);
}
