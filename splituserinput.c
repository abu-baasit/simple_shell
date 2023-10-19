#include "shell.h"
/**
 * splitUserInput - Function that splits the user input into tokens
 * and returns a pointer
 * @userInput: string of user input
 * Return: Return zero(success) or NULL/Fail
 */
char **splitUserInput(char *userInput)
{
	char **tokenArray = NULL;
	int numToken = 0, k = 0;
	char *tempPath = _strdup(userInput), *tempToken;
	char *DELIM = " \"\n\t\r";

	if (tempPath != NULL)
	{
		tempToken = strtok(tempPath, DELIM);
		while (tempToken != NULL)
			numToken++, tempToken = strtok(NULL, DELIM);
	}
	/* Increment token_num by 1 */
	numToken++;
	tokenArray = malloc(sizeof(char *) * numToken);
	if (tokenArray == NULL)
	{
		perror("Error allocating memory for tokens.");
		free(tempPath), free(tokenArray);
		exit(EXIT_FAILURE);
	}

	free(tempPath);
	tempPath = _strdup(userInput);
	tempToken = strtok(tempPath, DELIM);
	tokenArray[k] = _strdup(tempToken);

	while (tempToken != NULL)
	{
	k++;
		tempToken = strtok(NULL, DELIM);
		if (tempToken != NULL)
			tokenArray[k] = _strdup(tempToken);
	}
	tokenArray[k] = NULL;
	free(tempPath);
	return (tokenArray);
}
