#include "shell_K_J.h"


/**
  *implement_Separator -processes input with multiple commands separated by ;
  *@command: user-input command to be executed
  *
  *Return: (void)
  */
void implement_Separator(char *command)
{
	char *separator = ";"; /* commands split using ; as delimiter*/
	char *next_command = _strtok(command, separator);
	char *commands[32];
	int num_commands = 0;
	int i;

	while (next_command != NULL)
	{
		commands[num_commands++] = _strdup(next_command);
		next_command = _strtok(NULL, separator);
	}

	for (i = 0; i < num_commands; i++)
	{
		process_Command(commands[i]);
		free(commands[i]);
	}
}

/**
  *main - Entry point into the shell program
  *Description: All the functions and executables and called into the shell
  *program for execution and functionality at this point
  *
  *Return: status of 0 on success and 1 if the shell fails
  */
int main(void)
{
	char *command;
	int exit_status;

	signal(SIGINT, sigint_Handler);
	while (1)
	{
		shell_Prompt();
		command = _getline();

		if (command == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (_strlen(command) == 0)
		{
			free(command);
			continue;
		}
		command[_strcspn(command, "\n")] = '\0';

		/*if the command is "exit" before forking*/
		if (_strcmp(command, "exit") == 0)
		{
			free(command);
			break; /* Exit the loop & terminate the shell with status 0*/
		}
		else if (_strncmp(command, "exit ", 5) == 0)
		{
			exit_status = _atoi(command + 5);
			free(command);
			exit(exit_status);
		}
		else
		{
			implement_Separator(command);
		}
		free(command);
	}
	return (0);
}
