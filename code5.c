#include "shell.h"

void nasig(int sig);
int naexecute(char **args, char **front);

/**
* nasig - Prints a new prompt
* @sig: The signal.
*/
void nasig(int sig)
{
char *new_prompt = "\n$ ";

(void)sig;
signal(SIGINT, nasig);
write(STDIN_FILENO, new_prompt, 3);
}

/**
* naexecute - Executes a command.
* @args: An array of arguments.
* @front: A double pointer
*
* Return: If an error occurs - a corresponding error code.
*         O/w - The exit value of the last executed command.
*/
int naexecute(char **args, char **front)
{
pid_t child_pid;
int nastatus, naflag = 0, naret = 0;
char *command = args[0];

if (command[0] != '/' && command[0] != '.')
{
naflag = 1;
command = get_location(command);
}

if (!command || (access(command, F_OK) == -1))
{
if (errno == EACCES)
naret = (create_error(args, 126));
else
naret = (create_error(args, 127));
}
else
{
child_pid = fork();
if (child_pid == -1)
{
if (naflag)
free(command);
perror("Error child:");
return (1);
}
if (child_pid == 0)
{
execve(command, args, enviroment);
if (errno == EACCES)
naret = (create_error(args, 126));
free_env();
free_args(args, front);
free_alias_list(aliases);
_exit(naret);
}
else
{
wait(&nastatus);
naret = WEXITSTATUS(nastatus);
}
}
if (naflag)
free(command);
return (naret);
}

/**
* main - Runs a simple UNIX command interpreter.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: The return value of the last executed command.
*/
int main(int argc, char *argv[])
{
int ret = 0, retn;
int *exe_ret = &retn;
char *prompt = "$ ", *new_line = "\n";

name = argv[0];
hist = 1;
aliases = NULL;
signal(SIGINT, sig_handler);

*exe_ret = 0;
enviroment = _copyenv();
if (!enviroment)
exit(-100);

if (argc != 1)
{
ret = proc_file_commands(argv[1], exe_ret);
free_env();
free_alias_list(aliases);
return (*exe_ret);
}

if (!isatty(STDIN_FILENO))
{
while (ret != END_OF_FILE && ret != EXIT)
ret = handle_args(exe_ret);
free_env();
free_alias_list(aliases);
return (*exe_ret);
}

while (1)
{
write(STDOUT_FILENO, prompt, 2);
ret = handle_args(exe_ret);
if (ret == END_OF_FILE || ret == EXIT)
{
if (ret == END_OF_FILE)
write(STDOUT_FILENO, new_line, 1);
free_env();
free_alias_list(aliases);
exit(*exe_ret);
}
}

free_env();
free_alias_list(aliases);
return (*exe_ret);
}
