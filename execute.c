#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "shell.h"

#define MAX_ARGUMENT_LENGTH 100

void executeCommand(char *inputcmd)
{
    // Make a copy of the original command for external execution.
    char originalCommand[256];
    strncpy(originalCommand, inputcmd, sizeof(originalCommand));
    originalCommand[sizeof(originalCommand) - 1] = '\0';

    // Tokenize the command for internal built-in checks.
    char *args[MAX_ARGUMENT_LENGTH];
    char *tokens = strtok(inputcmd, " ");
    int i = 0;
    while (tokens != NULL)
    {
        args[i++] = tokens;
        tokens = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (args[0] == NULL)
        return;

    // Handling built-in commands
    if (strcmp(args[0], "exit") == 0)
    {
        exit(0);
    }
    else if (strcmp(args[0], "pwd") == 0)
    {
        system("cd"); // 'cd' alone prints the current directory in Windows
        return;
    }
    else if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
        {
            fprintf(stderr, "cd : expected argument\n");
        }
        else
        {
            if (_chdir(args[1]) != 0)
            {
                perror("cd");
            }
        }
        return;
    }

    // Execute external commands using unmodified originalCommand
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char command[256];
    snprintf(command, sizeof(command), "cmd.exe /C \"%s\"", originalCommand);

    if (!CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        printf("Error: Failed to execute command.\n");
        return;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
