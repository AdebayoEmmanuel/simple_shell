#include <stdio.h>
char *enter_command(char *msg)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t n_bytes = 0;
	
	/*prompt the user to enter a command*/
	printf("%s", msg);
	/*storing the number of bytes read from stdin into n_bytes of ssize_t type*/
	n_bytes = getline(&buffer, &buffer_size, stdin);
	/*replacing the last character in the string \n with null terminator*/
	buffer[n_bytes - 1] = '\0';

	return (buffer);

}
