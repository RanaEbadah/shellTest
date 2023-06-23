#include "shell.h"

int main(__attribute__((unused)) int argc, char *argv[], char *envp[])
{
    char *line = NULL, *path, *filePath;
    size_t readed, len;
    int errorNum = 1;
    char **args;

    
    while(1)
    {
        printf("$ ");
        readed = getline(&line, &len, stdin);
        printf ("command is Space %d\n",CommandIsSpace(line));
        if (((readed == 1) && (_strcmp(line, "\n") == 0)) || (CommandIsSpace(line) == 1))
        continue;
       

        path = getPathFromEnv(envp);
        args = handleCommandLine(line);

        if((args == NULL) || (path == NULL))
        return(1);

        filePath = isExec(path, args[0]);

        if(filePath == NULL)
        {
            printf("%s: %d: %s: not found\n", argv[0], errorNum, args[0]);
            errorNum++;
            continue;

        }
    }
        
    return (0);
}
