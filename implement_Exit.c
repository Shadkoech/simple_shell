#include "shell_K_J.c"

/**
  * implement_Exit - Hanled the exit command in shell
  * @command: Command entered by user
  * @args: Array of strings containing command argument
  * @arg_count: Number of arguments in args array
  */
void implement_Exit(char *command, char **args, int arg_count)
{
	if (arg_count > 2)
	{
		const char *message = "Usage: exit [status], status (Optional Integer)\n";

		write(2, message, _strlen(message));
	}
	else
	{
		int exit_status = 0, i;

		if (arg_count == 2)
		{
			int is_integer = 1;

			for (i = 0; args[1][1]; i++)
			{
				if (!_isdigit(args[1][i]))
				{
					is_integer = 0;
					break;
				}
			}
			if (is_integer)
			{
				exit_status = _atoi(args[1]);
			}
			else
			{
				const char *message = "Invalid exit status. Exiting with status 0.\n";

				write(2, message, _strlen(message));
			}
		}
		free(command);
		exit(exit_status);
	}
	free(command);
}
