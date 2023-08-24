#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

#define MAX_COMMAND 20

/**
 * program - A simple command line shell
 * @av: Arguments passed to the program
 * @env: Environment variables to display
 */
void program(char **av, char **env)
{
	char *pull = NULL;
	int x, w;
	size_t y = 0;
	ssize_t no_ch;
	char *fly[MAX_COMMAND];
	pid_t baby_pid;
	int pos;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "cisfun$ ", 8);

		no_ch = getline(&pull, &y, stdin);
		if (no_ch == -1)
		{
			free(pull);
			exit(0);
		}

		x = 0;
		while (pull[x])
		{
			if (pull[x] == '\n')
				pull[x] = 0;
			x++;
		}

		w = 0;
		fly[0] = strtok(pull, " ");
		while (fly[w] != NULL)
		{
			w++;
			fly[w] = strtok(NULL, " ");
		}

		baby_pid = fork();
		if (baby_pid == -1)
		{
			free(pull);
			exit(0);
		}

		if (baby_pid == 0)
		{
			if (execve(fly[0], fly, env) == -1)
				write(STDOUT_FILENO, av[0], _strlen(av[0]));
			exit(0);
		}
		else
			wait(&pos);
		free(pull);
	}
}
