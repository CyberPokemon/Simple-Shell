#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "shell.h"

#define MAX_CMD_LENGTH 1024

void shellLoop()
{
    char inputcmd[MAX_CMD_LENGTH];

    while(1)
    {
        printf("simple-shell>> ");
        
        if(fgets(inputcmd,MAX_CMD_LENGTH,stdin)==NULL)
        {
            printf("\n");
            break;
        }

        inputcmd[strcspn(inputcmd,"\n")]='\0';//removing the newline character present in the input command

        if(strcmp(inputcmd,"exit")==0)
        {
            break;
        }

        executeCommand(inputcmd);
    }
}


void shellStart()
{
    printf("Welcome to The Simple Shell\n");
    shellLoop();
}