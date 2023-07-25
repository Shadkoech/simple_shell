#include "shell_K_J.h"

/**
  *implement_cd - function that changes working directory
  *@command: user input command
  *@args: array of strings with command arguments
  *@arg_count: Number of elements in the array
  *
  *Return: void
  */
void implement_cd(char *command, char **args, int arg_count)
{
	const char *message;

	if (arg_count != 2)
	{
		message = "Usage: cd < current-directory>\n";
		write(2, message, _strlen(message));
	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			perror("cd failed");
		}
	}
	(void)command;
}
