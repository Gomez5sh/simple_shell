//#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#define PROMPT "#Cisfun/-> "

int main()
{

	char *arg[] = {"/bin/ls", "/home/cristian/Documents/simple_shell", NULL};
	char *bufo =  NULL;
	size_t buffosize;
	int chara, child;
	char *tmp;


	/* if (!bufo) */
	/* { */
	/* 	perror("Unable to allocate buffer"); */
	/* 	exit(1); */
	/* } */

	do{

		write(STDOUT_FILENO, PROMPT, 11);
		getline(&bufo, &buffosize, stdin);
		tmp = strtok(bufo, "\n");
		child = fork();
		if (child == 0)
		{
			execve(tmp, arg, NULL);
		}
		else
			wait(&chara);

		free(bufo);
	} while (1);
	return(0);
}
