#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **envron;

/******************custom String functions **********/
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strstr(char *searchString, char *mainString);

#include <signal.h>
#include <sys/types.h>
#include <stddef.h>

/**
 * struct Builtin - Structure of function and command
 * @functionCommand: Function to be called when comman    d matches
 * @command: Command to be compared
 */

typedef struct Builtin
{
	char *command;
	void (*functionCommand)(char **argv, char **env, char **tokenArray);
} Builtin;

/*digits and atoi*/
int _isdigit(int c);
int _atoi(char *s);

/********** Builtin functions control*********** */

void envFunction(char **argv, char **env, char **tokenArray);
void cdFunction(char **argv, char **env, char **tokenArray);
void exitFunction(char **argv, char **env, char **tokenArray);

/*************Custom String Prototypes***************/
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strstr(char *searchString, char *mainString);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

/*************Memory Allocation Prototypes***********/
void freeTokens(char **arrayTokens);
void *memory_reallocation(void *ptr, unsigned int old_val,
		unsigned int new_val);


/*Global status*/
int status;
int counter;

/*************Simple Shell Prototypes***************/
void alert_error(int fd, int command, char *s1, char *s2, char *s3);
char **pathSplitFunction(char *varPath);
char *findStringPath(char *command, char *path);
char *getPath(char **env);
void handle_signal(int signum);
int builtinControl(char **argv, char **env, char **tokenArray);
char **splitUserInput(char *userInput);
int controlPath(char **argv, char **env, char **tokenArray, int *counter);
void fullPathControl(char **tokenArray, char **env, char **argv, int input);

/**************Main functions**********************/
void interactnControl(char **argv, char **env, int *counter, int *input);
char **handleInput(char **argv, int *input);
void nonInteractive(char **argv, char **env);


/**********************SPECIAL CASE CONTROLLER ********/
int lostPathControl(char *inPath, char **tokenArray,
						  char **env, int *input, int *counter, char **argv);
#endif
