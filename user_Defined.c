#include "shell_K_J.h"

/**
  * _getenv - Get value of environment variable as per name
  * @name: Name of environment variable to retrieve
  *
  * Return: Pointer to value of environment variable or NULL
  */
char *_getenv(const char *name)
{
	extern char **environ; /* External variable to access the environment*/

	/* Iterate through the environment variables*/
	char *variable;
	int i, j;
	for (i = 0; environ[i] != NULL; i++)
	{
		variable = environ[i];
		j = 0;
		
		/* Compare the variable name with the requested name*/
		while (name[j] != '\0' && variable[j] != '=' && name[j] == variable[j])
		{
			j++;
		}

		/* If the names match and the current character is '=', return the value*/
		if (name[j] == '\0' && variable[j] == '=')
		{
			return variable + j + 1;
		}
	}

	/* Variable not found, return NULL*/
	return NULL;
}
/**
  * _getline - Read line of input from STDIN
  *
  * Return: Pointer to dynamically allocated buffer,
  * holding the input line
  */
char *_getline()
{
	char *buffer = malloc(MAX_BUFFER_SIZE);
	ssize_t bytesRead;

	if (!buffer)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	bytesRead = read(STDIN_FILENO, buffer, MAX_BUFFER_SIZE);
	if (bytesRead == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	if (bytesRead == 0)
	{
		/*EOF encountered, exit the shell*/
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	if (bytesRead > 0 && buffer[bytesRead - 1] == '\n')
	{
		buffer[bytesRead - 1] = '\0';
	}

	return buffer;
}

/**
  * _strtok - Tokenize (Split a string into smaller tokens, per delimiters)
  * @str: Pointer to input string to tokenize
  * @delim: Pointer to string of delimiters
  *
  * Return: Pointer to next token in input string or NULL
  */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken;
	char *token;

	if (str != NULL)
	{
		lastToken = str;
	}
	else if (lastToken == NULL)
	{
		return (NULL);
	}

	while (*lastToken != '\0' && _strchr(delim, *lastToken) != NULL)
	{
		lastToken++;
	}
	if (*lastToken == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}

	token = lastToken;
	while (*lastToken != '\0' && _strchr(delim, *lastToken) == NULL)
	{
		lastToken++;
	}
	if (*lastToken != '\0')
	{
		*lastToken = '\0';
		lastToken++;
	}
	return (token);
}

/**
  * _atoi - Converts string of digits to an integer
  * @s: String to convert to an integer
  *
  * Return: Integer value corresponding to string or 0
  */
int _atoi(char *s)
{
	int c = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (s[c])
	{
		if (s[c] == 45)
		{
			min *= -1;
		}

		while (s[c] >= 48 && s[c] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (s[c] - '0');
			c++;
		}

		if (isi == 1)
		{
			break;
		}

		c++;
	}
	ni *= min;
	return (ni);
}
/**
  * _isdigit - Checks if a character is a digit
  * @c: Character to be checked
  *
  * Return: 1 if character is a digit (0 - 9), else 0
  */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
