#include "header.h"

/**
 * main - Funtion to se the path.
 * @argc: Number of arguments.
 * @argv: Vector in one-dimension array.
 * Return: 0.
 */


char *_getenv(const char *name)
{
	char * temp;
	char * change;
	int n;

	while (!environ[n])
	{
		temp = environ[n];

		if (_strcmp((char *) name, temp) == 0)
		{
			change = strtok(temp, "= ");
			change = strtok(NULL, "\0");
			break;
		}

		temp++;
	}
	return (change);
}
