#include "shell_K_J.h"

/**
  * _setenv_Update - Update existing environment variable
  * @name: Name of environment variable to update.
  * @value: Value to assign to the environment variable
  *
  * Return: 0 on success, -1 if variable doesn't exist/memory error
  */
int _setenv_Update(const char *name, const char *value)
{
	char **env = environ;
	char *new_var;

	while (*env)
	{
		if (_strncmp(*env, name, _strlen(name)) == 0 && (*env)[_strlen(name)] == '=')
		{
			new_var = (char *)malloc(_strlen(name) + _strlen(value) + 2);
			if (new_var == NULL)
			{
				return (-1);
			}
			_strcpy(new_var, name);
			_strcat(new_var, "=");
			_strcat(new_var, value);
			free(*env);
			*env = new_var;
			return (0);
		}
		env++;
	}
	return (-1);
}

/**
  * _setenv_Add_New - Adds new environment variable to the shell
  * @name: Name of environment variable to add
  * @value: Value to assign to environment variable
  *
  * Return: 0 on success, -1 on failure or memory error
  */
int _setenv_Add_New(const char *name, const char *value)
{
	char *new_var, **new_env;
	int num_vars = 0, i;

	new_var = (char *)malloc(_strlen(name) + _strlen(value) + 2);
	if (new_var == NULL)
	{
		return (-1);
	}
	_strcpy(new_var, name);
	_strcat(new_var, "=");
	_strcat(new_var, value);

	while (environ[num_vars] != NULL)
	{
		num_vars++;
	}
	new_env = (char **)malloc((num_vars + 2) * sizeof(char *));
	if (new_env == NULL)
	{
		free(new_var);
		return (-1);
	}
	for (i = 0; i < num_vars; i++)
	{
		new_env[i] = environ[i];
	}
	new_env[i++] = new_var;
	new_env[i] = NULL;
	free(environ);
	environ = new_env;

	return (0);
}

/**
  * _setenv - Set or update environment variables in shell
  * @name: Name of environment variable to set
  * @value: Value to assign to set environment variable
  * @overwrite: Overwrite flag, 1 overwrite, 0 don't overwrite
  *
  * Return: 0 on success, -1 on invalid argumemt or memory error
  */
int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL || value == NULL)
	{
		/*Invalid arguments.*/
		return -1;
	}
	
	if (overwrite)
	{
		/*Update the existing environment variable or add a new one if it does not exist.*/
		return _setenv_Update(name, value);
	}
	else
	{
		/*Add a new environment variable if it does not exist.*/
		return _setenv_Add_New(name, value);
	}
}
