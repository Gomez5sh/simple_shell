#include "header.h"


/**
 * _strcmp - print the string
 * @s1: The evaluated input
 * @s2: The evaluated input
 * Return: dest
 */

int _strcmp(char *s1, char *s2)
{

	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{
		return (*s1 - *s2);
	}
}
