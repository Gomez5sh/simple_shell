#include "header.h"

/**
 * _child - funtion to exec in child process
 * @tmp: command without path
 * @arg: arguments of command
 * @bufo: pointer to buff malloc
 * Return: 0
 */
int _child(char *tmp, char *arg[], char *bufo)
{
	char *_findpath, *cadena;

	if (!tmp)/*if arg is NULL */
		free_buf("Enter a command\n", 16, bufo, "1");
	_findpath = findpath(environ, "PATH");
	cadena = strtok(_findpath, ":");
	while (cadena)
	{
		cadena = string_rec_path(tmp, cadena);
		execve(cadena, arg, NULL);
		cadena = strtok(NULL, ":");
	}
	write(STDOUT_FILENO, tmp, (_strlen(tmp)));
	free_buf(ERROR_MS, 12, bufo, "1");
	return (0);
}
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
			free_buf("\n", 1, bufo, "1");
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
			_child(tmp, arg, bufo);
		}
		else
			wait(NULL);
	}
	return (0);
}
