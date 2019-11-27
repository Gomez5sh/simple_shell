#include "header.h"

/**
 * main - funtion main of thw shell
 *
 * Return: exit (0) - fail (1)EOF
 */

int main(void)
{
	char *arg[] = {"/bin", NULL, NULL, NULL};
	char *bufo = NULL, *tmp = NULL, *xs = "98";
	size_t buffosize = 0;
	int child = 0, x = 0, strrec = 0;

	while (1)
	{
		write(STDOUT_FILENO, PROMPT, 6); /* print the prompt */
		signal(SIGINT, INThandler); /* detect signal CRTL C */
		x = getline(&bufo, &buffosize, stdin); /* obtain line */
		if (x == EOF) /* END OF FILE CTRL D */
			free_buf(NULL, 0, bufo, "1");
		tmp = strtok(bufo, "\n ");
		arg[1] = strtok(NULL, "\n "); /* arg[1] arguments to the funtion */
		arg[2] = strtok(NULL, "\n ");
		strrec = string_rec_exit(bufo); /* Funtion exit() */
		if (strrec == 1)
		{
			if (arg[1] == NULL)
				xs = NULL;
			free_buf(NULL, 0, bufo, xs);
		}
		child = fork(); /* Proceso Hijo */
		if (child == 0)
		{
			if (!tmp) /*if arg is NULL */
				free_buf("Enter a command\n", 16, bufo, "1");
			tmp = string_rec_path(tmp);/* Recogniza with function have or not PATH */
			if (execve(tmp, arg, NULL) == -1) /*EXECVE */
				free_buf(ERROR_MS, 12, bufo, "1");
			free_buf(NULL, 0, bufo, NULL);
			exit(0);
			return (0);
		}
		else
			wait(NULL);
	}
	return (0);
}
