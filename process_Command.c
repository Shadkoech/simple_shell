#include "shell_K_J.h"


/**
  *process_Command -Holds commands and executes them based on command's content
  *@command: action commands entered by user
  *
  *Return: (void)
  */
void process_Command(char *command)
{
	char *args[32];
	int arg_count = 0;
	char *token = _strtok(command, " ");

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = _strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (_strcmp(args[0], "exit") == 0)
	{
		implement_Exit(command, args, arg_count);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		implement_Cd(command, args, arg_count);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		implement_Env(command, args, arg_count);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		implement_Setenv(command, args, arg_count);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		implement_Unsetenv(command, args, arg_count);
	}
	else
	{
		execute_Command(command, args, arg_count);
	}
}
