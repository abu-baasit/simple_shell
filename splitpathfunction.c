#include "shell.h"

/**
*pathSplitFunction - this function splits the environment variable,
* returns a pointer
*@varPath: A string of directories to be splitted
*Return: Returns an array of string if true or NULL if false
*/
char **pathSplitFunction(char *varPath)
{
	char **tokenArray = NULL;
	int numToken = 0, k = 0;
	char *tempPath = _strdup(varPath);
	char *tempToken;

	if (varPath == NULL)
		return  (NULL);
	if (tempPath != NULL)
	{
		tempToken = strtok(tempPath, ":");
		while (tempToken != NULL)
			numToken++, tempToken = strtok(NULL, ":");
	}
numToken++;
	tokenArray = malloc(sizeof(char *) * numToken);
	if (tokenArray == NULL)
	{perror("Error allocating memory for tokens.");
		free(tempPath);
		return (NULL);
	}
	free(tempPath);
	tempPath = _strdup(varPath);
	tempToken = strtok(tempPath, ":");
	tokenArray[k] = _strdup(tempToken);

	while (tempToken != NULL)
		k++, tempToken = strtok(NULL, ":");
			tokenArray[k] = _strdup(tempToken);

			tempToken[k] = '\0';
			free(tempPath);
			return (tokenArray);
}
