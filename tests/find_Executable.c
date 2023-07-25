#include "shell_K_J.h"
/**
  * find_Executable - Find path of an executable in directories listed in  PATH
  * @command: Name of executable to find
  * @executable_path: Buffer to store full path of found executable
  * Return: Pointer to full path of executable or NULL if not found
  */
char *find_Executable(const char *command, char *executable_path)
{
	char *path_env, path_copy[MAX_PATH_LENGTH], *path_token;

	if (_strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
		{
			return (_strdup(command));
		}
		return (NULL);
	}
	path_env = _getenv("PATH");
	if (path_env == NULL)
	{
		char error_msg[] = "PATH environment variable not found. \n";

		write(2, error_msg, sizeof(error_msg) - 1);
		return (NULL);
	}
	_strncpy(path_copy, path_env, sizeof(path_copy) - 1);
	path_copy[sizeof(path_copy) - 1] = '\0';
	path_token = _strtok(path_copy, ":");
	while (path_token != NULL)
	{
		size_t path_len = _strlen(path_token);
		size_t command_len = _strlen(command);

		if (path_len + command_len + 2 <= MAX_PATH_LENGTH)
		{
			_strcpy(executable_path, path_token);
			_strcat(executable_path, "/");
			_strcat(executable_path, command);
			if (access(executable_path, X_OK) == 0)
				return (_strdup(executable_path));
		}
		path_token = _strtok(NULL, ":");
	}
	return (NULL);
}
