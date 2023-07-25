#include "shell_K_J.h"

/**
  *implement_Setenv - Function that sets specified environment variable
  *@command: user input command to be executed
  *@args: string array with command arguments
  *@arg_count: Number of elements in array arguments
  *
  *Return: (void)
  */
void implement_Setenv(char *command, char **args, int arg_count)
{
	const char *message;

	if (arg_count != 3)
	{
		message = "Usage: setenv VARIABLE VALUE\n";
		write(2, message, _strlen(message));
	}
	else
	{
		if (_setenv(args[1], args[2], 1) == -1)
		{
			perror("setenv");
		}
	}

	free(command);
}


/**
 * _unsetenv - custom function for unsetenv
 * @name: The name of the variable to unset.
 *
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
	char **env = environ;
	int found = 0;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
	{
		/*In the case of invalid argument*/
		return (-1);
	}
	/* Finding the variable in the environment list */
	while (*env)
	{
		if (_strncmp(*env, name, _strlen(name)) == 0 && (*env)[_strlen(name)] == '=')
		{
			found = 1;
			break;
		}
		env++;
	}
	if (found)
	{
		/* Shift the remaining environment variables */
		while (env[1] != NULL)
		{
			*env = env[1];
			env++;
		}
		*env = NULL;
	}
	else
	{
		return (-1); /*Variable not found*/
	}
	return (0);
}



/**
  *implement_Unsetenv - Handles removal of environment variables
  *environment variables
  *@command: input command to be executed
  *@args: string array with command arguments
  *@arg_count: number of elements in array of arguments
  */
void implement_Unsetenv(char *command, char **args, int arg_count)
{
	const char *message;

	if (arg_count != 2)
	{
		message = "Invalid command. Please check your input.\n";
		write(2, message, _strlen(message));
	}
	else
	{
		if (_unsetenv(args[1]) == -1)
		{
			perror("_unsetenv");
		}
	}

	free(command);
}





/**
  *implement_Env - iterates through and prints environment variables to
  *the standard-output
  *@command: input command to be fetch the variables
  *@args: string array with command arguments
  *@arg_count: number of elements in array of arguments
  *
  *Return: (void)
  */
void implement_Env(char *command, char **args, int arg_count)
{
	extern char **environ;
	char **env = environ;

	while (*env)
	{
		int len = 0;

		while ((*env)[len] != '\0')
			len++;

		write(1, *env, len);
		write(1, "\n", 1);

		env++;
	}

	(void)command;
	(void)args;
	(void)arg_count;
}
