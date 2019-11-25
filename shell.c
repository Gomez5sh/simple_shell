#include "header.h"
/**
 * main - funtion main of thw shell
 *
 * Return: exit (0)
 */
int main(int ac, char **ag, char **env_)
{
	char *arg[] = {"/bin/sh", NULL, NULL};
	char *bufo =NULL;
	char *tmp;
	size_t buffosize;
	int child, x, strrec = 0, execve_;

	(void)ac;
	(void)ag;
//	env = findpath(env_);
//	printf("env = %s\n", env);
	do {
		/* print the prompt */
		write(STDOUT_FILENO, PROMPT, 9);
		/* detect signal CRTL C */
		signal(SIGINT, INThandler);
		/* obtain line */
		x = getline(&bufo, &buffosize, stdin);
		if (x == EOF) /* END OF FILE CTRL D */
			free_buf("EOF detected\n", 13, bufo);
		tmp = strtok(bufo, " \n");
//		printf("tmp = %s\n",tmp); /* PA BORRAR ////// */

		/* arg[1] arguments to the funtion */
		arg[1] = strtok(NULL, "\n");
		/* Funtion exit() */
		strrec = string_rec_exit(bufo);
		if (strrec == 1)
			free_buf("Funtion exit()\n", 15, bufo);

		child = fork(); /* Proceso Hijo */
		if (child == 0)
		{
			if (!tmp) /*if arg is NULL */
				free_buf("Enter a command\n", 16, bufo);
//			printf("1\n");
			tmp = string_rec_path(tmp);
//			printf("new tmp: %s\n", tmp);
			execve_ = execve(tmp, arg, env_);
			/* execute function */
			if (execve_ == -1)
				free_buf(ERROR_MS, 33, bufo);
		}
		else
			wait(NULL);
	} while (1);
	return (0);
}
/* Toca hacer una funcion que unifique el PATH con el commando a ingresar (Concatenar) */
