# Unix Shell Implementation

The Simple Shell project reinforce the foundational C programming skills acquired throughout the course. This project involves the development of a basic UNIX command interpreter, commonly referred to as a shell. The shell allows users to execute commands and interact with the operating system, providing a practical application of system calls and process management.

## Key Concepts
In order to successfully complete this project, participants are expected to grasp the following concepts:

- **Unix Operating System:** Understanding the design and implementation of the original UNIX operating system.
- **Shell Basics:** Knowledge of the first version of the UNIX shell and its creator, Ken Thompson.
- **System Calls:** Familiarity with system calls and how they differ from regular functions.
- **Process Management:** Grasping concepts such as process IDs (pid) and parent process IDs (ppid).
- **Environment Manipulation:** Skills in manipulating the environment of the current process, including setting and unsetting environment variables.
- **Command Execution:** Learning how to execute commands using `execve` and managing processes effectively.
- **EOF Handling:** Understanding what EOF (end-of-file) signifies in the context of input and command execution.
- **Coding Standards:** Adhering to coding standards, including the Betty style guide, and ensuring code quality through testing and validation.

This project not only emphasizes technical skills but also encourages collaboration, problem-solving, and independent learning—key attributes for any successful software engineer.

## File Descriptions

1. **shell_K_J.c**
   - `implement_Separator()`: Processes input with multiple commands, separated by `;`.
   - `main()`: Entry point into the shell program.

2. **main_Helper.c**
   - `sigint_Handler()`: Handler for SIGINT signal (Ctrl+C).
   - `shell_Prompt()`: Generate and deploy shell prompt.

3. **shell_K_J.h**
   - Header file containing all the prototypes.

4. **small_Tools1.c**
   - `_strcmp()`: Compares two null-terminated strings.
   - `_strcpy()`: Copies a string from source to destination.
   - `_strdup()`: Duplicates a null-terminated string.
   - `_strchr()`: Locates the first occurrence of a character in a string.
   - `_strlen()`: Calculates the length of a string.

5. **small_Tools2.c**
   - `_strncpy()`: Copies at most n characters from source to destination.
   - `_strcat()`: Concatenates source to destination.
   - `_strcspn()`: Returns section of string without some characters.
   - `_strncmp()`: Compares two strings.

6. **user_Defined.c**
   - `_getenv()`: Gets environment variable value by name.
   - `_getline()`: Reads a line of input from STDIN.
   - `_strtok()`: Tokenizes (splits a string into smaller tokens).
   - `_atoi()`: Converts a string of digits to an integer.
   - `_isdigit()`: Checks if a character is a digit.

7. **set_Env.c**
   - `_setenv_Update()`: Updates an existing environment variable.
   - `_setenv_Add_New()`: Adds a new environment variable.
   - `_setenv()`: Set or update an environment variable.

8. **evn_Functions.c**
   - `_unsetenv()`: User-defined function for `unsetenv()`.
   - `_implement_Setenv()`: Sets the specified environment variable.
   - `_implement_Unsetenv()`: Handles removal of environment variables.
   - `_implement_env()`: Iterates through the environment and prints to STDOUT.

9. **find_Executable.c**
   - Finds the path of an executable in PATH directories.

10. **process_Command.c**
    - Holds commands and executes them.

11. **execute_Command.c**
    - Executes commands with specified arguments.

12. **implement_Exit.c**
    - Handles the exit command.
