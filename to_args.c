#include <string.h>
#include <stdlib.h>

char **to_args(char *cmd_str, size_t max_args)
{
	/*what we want: cmd_str = "/bin/ls -l -a" -> {"/bin/ls", "-l" "-a", NULL} we will delimit the split by space*/
	char *str = NULL;
	char **args = NULL;
	/*count for number of entered args*/
	size_t arg_count = 0;
	/*dynamically allocate size of maximum args bytes*/
	args = malloc(sizeof(*args) * max_args);
	/*delimiter to break string*/
	char *delim = " ";
	/*replaces the last character before the delim to a null terminator '\0' and
	 * returns a pointer to the begining of the token stored in str, does this for the rest tokens (sub strings)*/
	str = strtok(cmd_str, delim);

	while (str && arg_count < max_args - 1)
	{
		/*add element to args array*/
		/*for every time there is a str returned, the argument count also increase by 1*/
		args[arg_count++] = str;
		str = strtok(NULL, delim);

	}

	/*args array should be null terminated*/
	args[arg_count] = NULL;

	return (args);
}
