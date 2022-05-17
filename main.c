#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"


int main(void)
{
	char *cmd_str = NULL;
	char **args = NULL;
	
	/*we want to store the command and its args in an array like {"/bin'ls", "-l", "-a"}*/



	/*... enter the command*/
	cmd_str = enter_command("Command me master: ");

	/*our method to create an array of strings from command and flags*/
	args = to_args(cmd_str, 10);

	/*execute command*/
	if (execve(/*command*/args[0],/*arguments*/args,/*env vairables*/NULL) < 0);
	{
		/*an error occured??*/
		dprintf(STDERR_FILENO, "%s: Command not found\n", args[0]);
	}
	
	return (0);
}
