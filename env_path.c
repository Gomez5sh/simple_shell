#include "header.h"

int _strcmp(char *s1, char *s2);

/**
 * main - Funtion to se the path.
 * @argc: Number of arguments.
 * @argv: Vector in one-dimension array.
 * Return: 0.
 */


char *_getenv(const char *name)
{
	char *temp;
	int n = 0;
	extern char **environ;

	while (environ[n] != NULL)
	{
		temp = strtok(environ[n], "=");
		if ((_strcmp(temp,(char *) name)) == 0)
		{
			temp = strtok(NULL, "\0");
			return (temp);
		}
		n++;
	}
	return (NULL);
}



char *command(char *order)
{
	etern
	DIR *dir_env;
	struct dirent *entry;
	char *arch, *arch2;
	int n;
	char **change, **move, *envi;

	change = strdup(*order);
	move = strdup(*order);


	envi = _getenv("PATH");

	n = 0;

	while (n != NULL)
	{
		*change = strtok(*move, ":=");

		dir_env = opendir(*change);

		if(dir_env == NULL)
		{
			perror("Error to read directory.");
			return(1);
		}

		while((entry=readdir(dir_env)))
		{
			arch = entry->d_name;

			arch2 = strcmpdir(arch, order);

			if (arch == 0)
				return (*change);
		}
		n++;
		change++;
		move++;
	}

	return("Not Found");
}
