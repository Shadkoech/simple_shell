#include "shell_K_J.h"


/**
  *execute_command - executes commands with specified arguments in new process
  *@command: user input command to be executed
  *@args: array of string with command arguments
  *@arg_count: number of elements in array of arguments
  *
  *Return: (Void)
  */
void execute_Command(char *command, char **args, int arg_count)
{
	pid_t pid = fork();
	char *executable, *envp[] = {NULL}, executable_path[MAX_PATH_LENGTH];
	int len = 0;
	(void)arg_count;

	if (pid == 0)
	{
		executable = find_Executable(args[0], executable_path);
		if (executable)
		{
			execve(executable, args, envp);
			len += write(2, command, _strlen(command));
			len += write(2, ": ", 2);
			len += write(2, "1", 1); /*Exit status 1*/
			len += write(2, ": ", 2);
			len += write(2, args[0], _strlen(args[0]));
			len += write(2, ": not found\n", 12);
			free(executable);
			exit(EXIT_FAILURE);
		}
	else
	{
		len += write(2, command, _strlen(command));
		len += write(2, ": ", 2);
		len += write(2, "1", 1); /* Exit status 1*/
		len += write(2, ": ", 2);
		len += write(2, args[0], _strlen(args[0]));
		len += write(2, ": not found\n", 12);
		free(executable);
		exit(1); /* Use exit code 1 to indicate command not found*/
	}
	}
	else if (pid < 0)
	{
		perror("fork");
		free(command);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
}
