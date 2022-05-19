#include <string.h>
#include <stdlib.h>
/**
 * to_args - converts cmd_str to an array of command and args
 * what we want: cmd_str = "/bin/ls -l -a" -> {"/bin/ls", "-l" "-a", NULL}
 * we will delimit the split by space
 *
 * @max_args: maximum allowable args
 *
 * @cmd_str: command string
 *
 * str: token returned by strtok function
 *
 * args: argument array dynamically allocated
 * by the call to malloc to size of max allowed arg
 *
 * arg_count: number of entered args
 *
 * delim: delimeter to break string
 * in this case, its space " "
 *
 * strtok: takes command string as arg and the delimeter
 * strtok replaces the last character before tge delim to a
 * null terminator '/0' and returns a pointer to the
 * beginning of the token stored in str, does
 * same for the rest of the token (sub strings)
 *
 * add element to args array for every time there is
 * a str returned, the argument count also increases by 1
 *
 * args array should be null terminated
 *
 * Return: (args)
 **/
char **to_args(char *cmd_str, size_t max_args)
{
	char *str = NULL;

	char **args = NULL;

	size_t arg_count = 0;

	args = malloc(sizeof(*args) * max_args);

	char *delim = " ";

	str = strtok(cmd_str, delim);

	while (str && arg_count < max_args - 1)
	{
		args[arg_count++] = str;
		str = strtok(NULL, delim);
	}

	args[arg_count] = NULL;

	return (args);
}
