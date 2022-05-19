


int main(int ac, char **av)
{
	char *cmd_str = NULL;
	char **args = NULL;

	/*infinite loop to keep collecting command*/
	while (1)
	{
		/*non interactive mode*/
		if (ac > 1)
		{
			/*point arg to second command line argument that ran the program*/
			args = av + 1;
		}
		else
		{
	/*interactive mode*/
	/*read command from user*/
	/*... enter the command*/
	cmd_str = enter_command("Command me master: ");
	/*our method to create an array of strings from command and flags*/
	args = to_args(cmd_str, 10);
		}
	/*execute command*/
	execve(/*command*/args[0],/*arguments*/args,/*env vairables*/NULL);

	 /*an error occured??*/
	dprintf(STDERR_FILENO, "%s: Command not found\n", args[0]);

	if (ac > 1)
		break;

	}


	return (0);
}
