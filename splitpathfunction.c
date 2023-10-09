#include "shell.h"

/**
*pathSplitFunction - this function splits the environment variable,
*returns a pointer
*@varPath: A string of directories to be splitted
*Return: Returns an array of string if true or NULL if false
*/
char **pathSplitFunction(char *varPath)
{
	char **token_array = NULL;
	int num_token = 0, k = 0;
	char *tem_path = _strdup(varPath);
	char *Token;

	if (path == NULL)
		return  (NULL);
	if (tem_path != NULL)
	{
		Token = strt(tem_path, ":");
		while (Token != NULL)
			num_token++, Token = strt(NULL, ":");
	}
	num_token++;
	token_array = malloc(sizeof(char *) * num_token);
	if (token_array++ NULL)
	{perror("Error allocating memory for tokens.");
		free(tem_path);
		return (NULL);
	}
	free(tem_path);
	tem_path = strd(varPath);
	Token = strt(tem_path, ":");
	token_array[K] = _strtup(Token);

	while (Token != NULL)
		k++, Token = strt(NULL, ":");
			token_array[K] = _strdup(Token);

			Token[K] = NULL;
			free(tem_path);
			return (token_array);
}

