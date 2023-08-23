#include <sys/wait.h>
#include "shell.h"
#include <unistd.h>

/**
 * program - A simple cmd line shell
 * @av: Takes arguments
 * @env: display env var
 */

void program(char **av, char **env)
{
	char *pull = NULL;
	int x, pos;
	size_t y = 0;
	ssize_t no_ch;
	char *fly[] = {NULL, NULL};
	pid_t baby_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");

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
		fly[0] = pull;
		baby_pid = fork();
		if (baby_pid == -1)
		{
			free(pull);
			exit(0);
		}
		if (baby_pid == 0)
		{
			if (execve(fly[0], fly, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&pos);
	}
}
