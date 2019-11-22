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
