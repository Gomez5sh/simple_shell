//#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#define PROMPT "#Cisfun> "
#define ERROR_MS "shell: No such file or directory\n"

int main()
{

	char *arg[] = {"/bin/", NULL};
	char *bufo =  NULL;
	size_t buffosize;
	int child, x;
	char *tmp;

	do{

		write(STDOUT_FILENO, PROMPT, 9);
		x = getline(&bufo, &buffosize, stdin);
		if (x == EOF)
		{
			write(STDOUT_FILENO, "^D\n", 3);
			free(bufo);
			exit(EXIT_FAILURE);
		}
		tmp = strtok(bufo, "\n");
		child = fork();
		if (child == 0)
		{
			if (execve(tmp, arg, NULL) == -1)
			{
				write(STDOUT_FILENO, ERROR_MS, 33);
			}
		}
		else
		{
			wait(NULL);
		}
	} while (1);
	return(0);
	
}
