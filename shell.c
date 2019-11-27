#include "header.h"
extern char **environ;
/**
 * main - funtion main of thw shell
 *
 * Return: exit (0) - fail (1)EOF
 */
int main(int ac, char *ag[])
{
	char *arg[] = {"/bin/sh", NULL, NULL, NULL};
	char *bufo =NULL, *env;
	char *tmp;
	char *xs = "98";
	size_t buffosize;
	int child, x, strrec = 0, execve_, state, len_env, cont, st = 1;

	(void)ac;
	(void)ag;
	do {
		if (st == 1)
		{
			for (cont = 0, len_env = 0; environ[cont] != NULL; cont++)
			{
				printf("ENV[%d]: %s\n",cont, environ[cont]);
				len_env++;
			}
		}
//		printf("len_env %i\n",len_env);
//		environ[18] = "PWD=/home";
		printf("____________________________________\n");
		st = 0;

		/* print the prompt */
		write(STDOUT_FILENO, PROMPT, 2);
		/* detect signal CRTL C */
		signal(SIGINT, INThandler);
		/* obtain line */
		x = getline(&bufo, &buffosize, stdin);
		if (x == EOF) /* END OF FILE CTRL D */
			free_buf("^D Bye Bye\n", 11, bufo, "1");
		tmp = strtok(bufo, " \n");
		/* arg[1] arguments to the funtion */
		arg[1] = strtok(NULL, "\n ");
		arg[2] = strtok(NULL, " \n");
		/* Funtion exit() */
		strrec = string_rec_exit(bufo);
		if (strrec == 1)
		{
			if(arg[1] == NULL)
				xs = NULL;
			free_buf(NULL, 0, bufo, xs);
		}
		child = fork(); /* Proceso Hijo */
		if (child == 0)
		{
			if (!tmp) /*if arg is NULL */
				free_buf("Enter a command\n", 16, bufo, "1");
			/* call to Specifica environment $ENVIRONMENT */
			if (tmp[0] == '$')
			{
				env = findpath(environ, tmp);
				printf("env:%s\n", env);
				free_buf(NULL, 0, bufo, "1");
			}
			/* Recogniza with function have or not PATH */
			tmp = string_rec_path(tmp);
			if (tmp[0] == 'c' && tmp[1] == 'd')
				change_dir(arg[1], bufo);
			/* EXECVE Function */
			execve_ = execve(tmp, arg, environ);
			if (execve_ == -1)
				free_buf(ERROR_MS, 33, bufo, "1");
			return (0);
		}
		else
			wait(&state);
	} while (1);
	return (0);
}
