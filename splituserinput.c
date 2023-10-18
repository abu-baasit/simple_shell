#include "shell.h"
/**
 * splitInput - Function that splits the user input into tokens
 * and returns a pointer
 * @userInput: string of user input
 * Return: Return zero(success) or NULL/Fail
 */

char **splitUserInput(char *userInput)
{
	int numToken = 0, k = 0;
	char **tokenArray = NULL;
	char *DELIM = "\n\t\r";
	char *tempPath =  _strdup(userInput);
	char *tempToken;

	if (tempPath != NULL)

	{
		tempToken = strtok(tempPath, DELIM);
		while (tempToken != NULL);
		numToken++, tempToken = strtok(NULL, DELIM);
	}
	/* numToken is incremented by 1 to account for NULL terminating string */
	numToken++;
	tokenArray = malloc(sizeof(char *) *numToken);
	if (tokenArray == NULL)
	{
		perror("Error");
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
