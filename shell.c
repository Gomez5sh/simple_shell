#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#define PROMPT "#Cisfun> "
#define ERROR_MS "shell: No such file or directory\n"

/**
 * main - funtion main of thw shell
 *
 * Return: exit (0)
 */
int main(void)
{
	char *arg[] = {"/bin/sh", NULL, NULL};
	char *env[] = {"PATH=/bin:/usr/bin:/bin/bash", NULL};
	char *bufo =  NULL, *tmp;
	size_t buffosize;
	int child, x;

	do {
		write(STDOUT_FILENO, PROMPT, 9);
		x = getline(&bufo, &buffosize, stdin);
		if (x == EOF)
		{
			write(STDOUT_FILENO, "^D\n", 3);
			free(bufo);
			exit(EXIT_FAILURE);
		}
		tmp = strtok(bufo, " \n");
		arg[1] = strtok(NULL, "\n");
		child = fork();
		if (child == 0)
		{
			if (execve(tmp, arg, env) == -1)
			{
				write(STDOUT_FILENO, ERROR_MS, 33);
				free(bufo);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(NULL);
	} while (1);
	return (0);
}
