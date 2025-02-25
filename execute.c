#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "shell.h"

#define MAX_ARGUMENT_LENGTH 100

void executeCommand(char *inputcmd)
{
    char* args[MAX_ARGUMENT_LENGTH];
    char* tokens=strtok(inputcmd," ");
    int i=0;

    while(tokens!=NULL)
    {
        args[i]=tokens;
        i++;
        tokens=strtok(NULL," ");
    }
    args[i]=NULL;
}