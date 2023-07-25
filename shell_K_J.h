#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define MAX_BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 4096

/*String functions*/
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strchr(const char *s, int c);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
size_t _strcspn(const char *str, const char *reject);
int _strncmp(const char *str1, const char *str2, size_t n);

/*Conversion functions*/
int _atoi(char *s);
int _isdigit(int c);

/*Environment functions*/
char *_getenv(const char *name);
char *_strtok(char *str, const char *delimiters);
char *find_Executable(const char *command, char *executable_path);

/*Input functions*/
char *_getline();

/*Signal handler*/
void sigint_Handler(int signum);

/*Built-in commands*/
void implement_Exit(char *command, char **args, int arg_count);
void implement_Cd(char *command, char **args, int arg_count);
int _setenv(const char *name, const char *value, int overwrite);
void implement_Setenv(char *command, char **args, int arg_count);
int _unsetenv(const char *name);
void implement_Unsetenv(char *command, char **args, int arg_count);
void implement_Env(char *command, char **args, int arg_count);
void implement_Separator(char *command);

/*Shell functions*/
void shell_Prompt(void);
void process_Command(char *command);
void execute_Command(char *command, char **args, int arg_count);

extern char **environ; /*Global variable*/

#endif
