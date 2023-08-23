#include "shell.h"

/**
 * main - A simple model of shell interface
 * @ac: the arguments to be taken
 * @av: the arguments var to be printed
 * @env: the envronment var to be printed
 * return: Always (0) false
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		program(av, env);

	return (0);
}
