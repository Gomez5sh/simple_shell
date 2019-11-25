#include "header.h"
/** 1
 * Compare if ths command have path or full path
 * @s: command line
 * return full path create to execve
 */
int _strcmp(char *tmp)
{
	int cont, num = 0;
	char *str = "PATH";

	for (cont = 0; str[cont] != '\0'; cont++)
	{
		if (tmp[cont] == str[cont])
			num++;
		if (num == 4)
		{
//			printf("PATH finded\n");
			return (1);
		}
	}
	return (0);
}
/** 2
 *
 *
 *
 */
char *findpath(char **env)
{
	int cont;
	char *ret_path = NULL;

	for (cont = 0; env[cont] != NULL; cont ++)
	{
		ret_path = strtok(env[cont], "=");
		if (_strcmp(ret_path) == 1)
		{
			ret_path = strtok(NULL, "\n");
			return(ret_path);
		}
	}
	write(STDOUT_FILENO, ERROR_PATH, 16);
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
