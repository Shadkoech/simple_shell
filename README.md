This is Collaboration project meant to practice C-fundamentals learnt so far, through building a basic unix shell implementation.

1- shell_K_J.c - implement_Separator() Processes input with multiple commands, separated 
				       by;
		 Main() Entry point into the shell program
2- main_Helper.c - sigint_Handler() Handler for SIGINT signal (Ctrl+C)
	            shell_Prompt() Generate and deploy shell prompt
3- shell_K_J.h - Header file, contains all the prototypes
4- small_Tools1.c - _ strcmp() Compares two null-terminated strings
		    _ strcpy() Copies a string from source to destination
		    _ strdup() Duplicates a null-terminated string
		    _ strchr() Locates first occurrence of a character in a string
		    _ strlen() Calculates the length of a string
5- small_Tools2.c - _ strncpy() Carries at most n characters from source to destination
 	            _ strcat() Concatenates source to destination
		    _ strcspn() Returns section of string without some characters
		    _ strncmp() Compares two strings
6- user_Defined.c - _ getenv() Gets environment variable value as per name
		    _ getline() Read line of input from STDIN
	   	    _ strtok() Tokenizes (Splits a string into smaller tokens)
		    _ atoi() Converts string of digits to an integer
		    _ isdigit() Checks if a character is a digit
7- set_Env.c - _ setenv_Update() Updates existing environment variable
	       _ setenv_Add_New() Adds new environment variable
	       _ setenv() Set or update environment variable
8- evn_Functions.c - _ unsetenv() User-defined function for unsetenv()
		     _ implement_Setenv() Sets specified environment variable
		     _ implement_Unsetenv() Handles removal of environment variables
		     _ implement_env() Iterates through env and prints to STDOUT
9- find_Executable.c - Finds path of an executable in PATH directories
10- process_Command.c - Holds commands and executes them
11- execute_Command.c - Executes commands with specified arguments
12- implement_Exit.c - Handles exit command
