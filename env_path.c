#include "header.h"

/**
 * main - Funtion to se the path.
 * @argc: Number of arguments.
 * @argv: Vector in one-dimension array.
 * Return: 0.
 */

extern char **environ;

char *_getenv(const char *name)
{
	char **path;
	char n = 10;

	for(path=environ; *path != NULL; path++)
	{
		write(STDOUT_FILENO, (char *) *path, strlen(*path));
		write(1, &n, 1);
	}


	return (0);
}
