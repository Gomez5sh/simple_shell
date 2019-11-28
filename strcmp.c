#include "header.h"
/**
 * _strcmp - Compare if ths command have path or full path - 1
 * @tmp: command line
 * @str: string to compare
 * Return: full path create to execve
 */
int _strcmp(char *tmp, char *str)
{
	int cont, num = 0;

	for (cont = 0; str[cont] != '\0'; cont++)
	{
		if (tmp[cont] == str[cont])
			num++;
		if (num == 4)
			return (1);
	}
	return (0);
}
/**
 * findpath - search the specific variable environment - 2
 * @env: all enviremnt array key-value
 * @to_find: key to search
 * Return: string value
 */
char *findpath(char **env, char *to_find)
{
	int cont;
	char *ret_path = NULL;

	for (cont = 0; env[cont] != NULL; cont++)
	{
		ret_path = strtok(env[cont], "=");
		if (_strcmp(ret_path, to_find) == 1)
		{
			ret_path = strtok(NULL, "\n");
			return (ret_path);
		}
	}
	write(STDOUT_FILENO, ERROR_PATH, 18);
	return (NULL);
}
/**
 * string_rec_path - funtion check if string have or not the path - 3
 * @tmp: string of getline
 * @env: environmet
 * Return: string with path
 */
char *string_rec_path(char *tmp, char *env)
{
	char *ret;

	if (tmp[0] == '/')
		return (tmp);
	ret = _strcat(env, tmp);
	return (ret);
}
/**
 * _atoi - converti strings in INT - 4
 * @s: string to convert
 * Return: int number
 */
int _atoi(char *s)
{
	int number, sign = 0, lenght = 0;
	unsigned int n = 0;

	while (s[lenght] != '\0')
	{
		if (s[lenght] == '-')
		{
			sign++;
		}
		if (s[lenght] >= '0' && s[lenght] <= '9')
		{
			n = 10 * n + (s[lenght] - '0');
			if (s[lenght + 1] < '0' || s[lenght + 1] > '9')
				break;
		}
		lenght++;
	}
	if (sign % 2 != 0)
		number = n * -1;
	else
		number = n;
	return (number);
}
