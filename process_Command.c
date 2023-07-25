#include "shell_K_J.h"


/**
  *process_command -Holds commands and executes them based on command's content
  *@command: action commands entered by user
  *
  *Return: (void)
  */
void process_command(char *command)
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
		implement_exit(command, args, arg_count);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		implement_cd(command, args, arg_count);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		implement_env(command, args, arg_count);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		implement_setenv(command, args, arg_count);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		implement_unsetenv(command, args, arg_count);
	}
	else
	{
		execute_command(command, args, arg_count);
	}
}
