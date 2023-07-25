#include "shell_K_J.h"

/**
  * sigint_Handler - Handler for SIGINT signal (Ctrl + C)
  * @signum: Signal number (Unused)
  */
void sigint_Handler(int signum)
{
	write(STDOUT_FILENO, "\n", 1);
	(void)signum;
}


/**
  * shell_Prompt - Generate and display the shell prompt
  *
  */
void shell_Prompt(void)
{
	char working_Curr_Dir[1024];
	char prompt[1026];
	size_t len;

	if (isatty(STDIN_FILENO)) /*interactive mode*/
	{
		getcwd(working_Curr_Dir, sizeof(working_Curr_Dir));
		len = _strlen(working_Curr_Dir);

		if (len + 2 <= sizeof(prompt))
		{
			_strcpy(prompt, working_Curr_Dir);
			prompt[len] = '#';
			prompt[len + 1] = ' ';
			prompt[len + 2] = '\0';

			write(STDOUT_FILENO, prompt, _strlen(prompt));
		}
		else
		{
			/*Handle buffer overflow here, incase space for prompt not enough*/
		}
	}
}
