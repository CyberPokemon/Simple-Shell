#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
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

    if(args[0]==NULL)
    return;

    //Handling inbuilt commands

    if(strcmp(args[0],"exit")==0)
    {
        exit(0);
    }
    else if(strcmp(args[0],"cd")==0)
    {
        if(args[1]==NULL)
        {
            fprintf(stderr,"cd : expected arguments\n");
        }
        else
        {
            if(chdir(args[1])!=0)
            {
                perror("cd");
            }
        }
        return;
    }

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si,sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi,sizeof(pi));

    char command[256];
    snprintf(command,sizeof(command), "cmd.exe /c %c",inputcmd);

    if(!CreateProcess(NULL,command,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))
    {
        printf("Error : Failed to execute command.\n");
        return;
    }

    WaitForSingleObject(pi.hProcess,INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}