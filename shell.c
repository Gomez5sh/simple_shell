#include "header.h"
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
	int child, x, strrec;

	do {
		write(STDOUT_FILENO, PROMPT, 9);
		signal(SIGINT, INThandler);
		x = getline(&bufo, &buffosize, stdin);
		if (x == EOF)
			free_buf("EOF detected\n", 13, bufo);
		tmp = strtok(bufo, " \n");
		arg[1] = strtok(NULL, "\n");
		strrec = string_rec(tmp);
		if (strrec == 1) /* Funtion exit() invoqued */
			free_buf("Funtion exit()\n", 15, bufo);
		child = fork();
		if (child == 0)
		{
			if (!tmp) /*if arg is NULL */
				free_buf(NULL,0,bufo);
			if (execve(tmp, arg, env) == -1)
				free_buf(ERROR_MS, 33, bufo);
		}
		else
			wait(NULL);
	} while (1);
	return (0);
}
