#include "shell_K_J.h"

/**
  * _strcmp - Function compares two null-terminated strings
  * @s1: First string to compare
  * @s2: Second string to compare
  *
  * Return: An integer >, =, < or 0
  */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
  * _strcpy - Copy null-terminated string from source to destination
  * @dest: Destination buffer to copy to
  * @src: Source string to copy
  *
  * Return: Pointer to beggining of the destination buffer
  */
char *_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0'; /* Null-terminate the destination string*/

	return (original_dest);
}

/**
  * _strdup - Duplicate a null-terminated string
  * @src: Null-terminated string to be duplicated
  *
  * Return: Pointer to allocated duplicate string or NULL
  */
char *_strdup(const char *src)
{
	size_t len = _strlen(src), i;
	char *dest = (char *)malloc((len + 1) * sizeof(char));

	if (dest != NULL)
	{
		for (i = 0; i <= len; i++)
		{
			dest[i] = src[i];
		}
	}

	return (dest);
}
/**
  * _strchr - Locate first occurrence of a character
  * @s: Null-terminated string to search
  * @c: Character to locate
  *
  * Return: Pointer to first occurrence of 'c' in 's' or NULL
  */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}

/**
  * _strlen - Calculate length of string
  * @s: String whose length will be calculated
  *
  * Return: Length of string 's'
  */
int _strlen(const char *s)
{
	int c = 0;

	while (*s != '\0')
	{
		c++;
		s++;
	}
	return (c);
}
