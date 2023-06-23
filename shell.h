#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<limits.h>
#include<fcntl.h>
#include<limits.h>
#include<errno.h>


/*string functions*/
int _strlen(char *str);
char *concat_string(char *strDest, char *strSrc);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, int n);


/*shell.c functions*/
char** handleCommandLine(char *command);
char* getPathFromEnv(char *env[]);
char* isExec(char *path, char *fileName);
int CommandIsSpace(char *command);


#endif
