#include "shell.h"

/**
*handleCommandLine - get args fromCommand
*@command: the comand
*Return: array of arguments
*/
char** handleCommandLine(char *command)
{
    char **args;
    char *token;
    int tokenCount = 0;

    if (command == NULL)
    return (NULL);
    
    args = malloc (30 * sizeof(char*));
    if(args == NULL)
    return (NULL);

    token = strtok(command, " ");

    while ((token != NULL) && tokenCount < 50)
    {
        args[tokenCount] = token;
        tokenCount++;

        token = strtok(NULL, " ");
    }
    
    args[tokenCount] = NULL;
    
    return (args);
}


/**
*getPathFromEnv - extract the PATH from main env args
*@env: the main env args.
*@path: the PATH will be here.
*Return: 1 or 0
*/
char* getPathFromEnv(char *env[])
{
    int i, same;
    char *path = NULL;

    for (i = 0; env[i] != NULL; i++)
    {
        same = _strncmp(env[i], "PATH=", 5);
        if (same == 0)
        {
            path = env[i] + 5;
            break;;
        }
    }
    return (path);
}

/**
*isExec - check if the command is executable or not
*(found on the PATH or not)
*@str: the string that we will get it's length.
*Return: the lenght of the string / -1 if the sting is null
*/
char* isExec(char *path, char *fileName)
{
    char *token;
    char *filePath;
    struct stat filestat;

    if ((path == NULL) || (fileName == NULL))
    return (NULL);
    
    filePath = concat_string("/", fileName);
    
    if (filePath == NULL)
    return (NULL);

    token = strtok(path, ":");

    while (token != NULL)
    {
        token = concat_string(token, filePath);

        if(stat(token, &filestat) == 0)
        {
            return (token);
        }
        else
        token = strtok(NULL, ":");
    }

    return (NULL);
}

/**
*CommandIsSpace - check if the command is just spaces
*@comman: The command to be checked
*Return: if pace 1, if no 0
*/
int CommandIsSpace(char *command)
{
    int i = 0, isSpace = 0;

    for (i = 0; i < _strlen(command); i++)
    {
        if (command[i] == ' ')
        isSpace = 1;
        else
        {
            isSpace = 0;
            break;
        }
    }

    printf("isSpace %d\n", isSpace);
    return(isSpace);
}
