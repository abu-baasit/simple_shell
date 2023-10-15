#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **envron

/******************custom String functions **********/
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strstr(char *searchString, char *mainString);

/**
*struct Builtin - Structure of command and function
*@command:command to be compared
*@functionCommand:function to be called
*/
typedef struct Builtin
{
	char *command;
	void (*functionCommand)(char **av, char **env, char **tokenArray);
} Builtin;

/*********Global Variable************/
int counter;
int status;

/************Main Functions***********/
void interactnControl(char **av, int *counter, char **env, int *input);
void nonInteractive(char **av, char **env);
char **handleInput(char **av, int *input);

/********Spcial Functions*************/
int lostPathControl(char *inPath, char **av, char **tokenArray,
		char **env, int *input, int *counter);

/************builtin functions***************/
void cdFunction(char **av, char **env, char **tokenArray);
void envFunction(char **av, char **env, char **tokenArray);
void exitFunction(char **av, char **env, char **tokenArray);
/**************Memory Prototypes*********/
void freeTokens(char *arrayToken);
void *memory_reallocation(void *ptr, unsigned int old_val,
		unsigned int new_val);

/*************atoi and Digits handler**************/
int _atoi(char *s);
int _isdigit(int c);

/***********Prototypes used******************/
int controlPath(char **av, char **env, char **tokenArray, int input);
int builtinControl(char **av, char *env, char **tokenArray);
char **pathSplitFunction(char *varPath);
char **handleInput(char *userInput);
char *getPath(char **env);
char *findStringPath(char *command, char *path);
void handle_signal(int signalnumber);
void fullPathControl(char **av, char **env, char **tokenArray,
		int input);
void alert_error(int fdesc, int commandNo, char *s1, char *s2, char *s3);

#endif
