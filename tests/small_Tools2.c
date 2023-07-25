#include "shell_K_J.h"

/**
  *_strncpy - Copies at most n character from the source to dest string
  *@src: The string to copy characters from
  *@dest: pointer to string of copied characters
  *@n: The max number of characters to copy
  *
  *Return: Pointer to begining of the destination string
  */
char *_strncpy(char *dest, const char *src, size_t n)
{
	char *original_dest = dest;

	/* Copies at most n characters from source to destination*/
	while (n > 0 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	/* If there are still remaining characters to be copied,*/
	/* fill the destination with null bytes.*/

	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}

	return (original_dest);
}



/**
  *_strcat - function that concatenates source to destination string
  *@dest: Destination to the concatenated string
  *@src: Source of the concatenated string
  *
  *Return: NULL
  */
char *_strcat(char *dest, const char *src)
{
	char *original_dest = dest;

	/* Move the destination pointer to the end of the string*/
	while (*dest != '\0')
	dest++;

	/* Copy characters from the source to the destination*/
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	/* Add the null-terminator at the end of the concatenated string*/
	*dest = '\0';

	return (original_dest);
}


/**
  *_strcspn -Returns section of str without matching characters in rejected str
  *@str: pointer to the first string to check
  *@reject: pointer to the string to check rejected char
  *
  *Return: length of initial character without any match to rejected str
  */
size_t _strcspn(const char *str, const char *reject)
{
	const char *s;
	const char *r;

	for (s = str; *s != '\0'; s++)
	{
		for (r = reject; *r != '\0'; r++)
		{
			if (*s == *r)
				return ((size_t)(s - str));
		}
	}

	return ((size_t)(s - str));
	/* Incase no characters match, return the length of the string.*/
}


/**
  *_strncmp - Function comparing two strings
  *@str1: First string to compare
  *@str2: Second string to compare
  *@n: Max number of characters to compare
  *
  *Return: position of the integer identified
  */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}

	if (n == 0)
		return (0);

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

