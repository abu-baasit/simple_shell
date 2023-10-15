#include "shell.h"

/**
* handleInput - A function that process
* user input and splits the input into tokens
* @av: handles command line argument
* @input: basically process input
* Return: return strings of array
*/
char **handleInput(char **av, int *input)
{
	ssize_t read_char;
	char **tokenArray = NULL;
	char *userString = NULL;
	size_t buf_size = 0;
	int k = 0;

	signal(SIGINT, handle_signal);
	read_char = getline(&userString, &buf_size, stdin);
	if (read_char < 0)
{
	free(userString);
	if (*input == 1)
		write(1, "\n", 1);
	exit(EXIT_SUCCESS);
}
	while (userString[k])
{
	if (userString[0] != '#' && userString[k] ==
			'#' && userString[k - 1] != ' ')
	break;

	if (userString[k] == '#')
	userString[k] = '\0';
	k++;
}
	tokenArray = handleInput(userString);
	if (tokenArray == NULL)
{
	free(userString), freeTokens(tokenArray);
	perror(av[0]);
	exit(EXIT_FAILURE);
}
	free(userString);
	return (tokenArray);
}
