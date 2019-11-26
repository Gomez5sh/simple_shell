#include "header.h"
/** 1
 * Compare if ths command have path or full path
 * @s: command line
 * return full path create to execve
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
/** 2
 *
 *
 *
 */
char *findpath(char **env, char *to_find)
{
	int cont;
	char *ret_path = NULL;

	for (cont = 0; env[cont] != NULL; cont ++)
	{
		ret_path = strtok(env[cont], "=");
		if (_strcmp(ret_path, (to_find + 1)) == 1)
		{
			ret_path = strtok(NULL, "\n");
			return(ret_path);
		}
	}
	write(STDOUT_FILENO, ERROR_PATH, 18);
	return (NULL);
}
/** 3
 * str_
 *
 *
 */
char *string_rec_path(char *tmp)
{
	char path[] = "/bin/";

	if (tmp[0] == '/')
		return(tmp);
	return(_strcat(path, tmp));
}
/** 4
 *
 *
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

/** 4
 *
 *
 *
 */
void change_dir(char *newdir, char *bufo)
{
	printf("New Dir");
	chdir(newdir);
	free_buf(NULL, 0, bufo, "0");
}
