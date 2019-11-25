#include "header.h"
/**
 * _strlen - Count char - 1
 * @s: funtion
 * Return: 0 Succes
 */
int _strlen(char *s)
{
	int contchar = 0;

	while (s[contchar] != 0)
	{
		contchar++;
	}
	return (contchar);
}
/**
 * string_rec - funtion recognize the string arg when ir a call system funtion - 2
 * @s: string arg
 * Return: (0)none (1)exit (2)env
 */
int string_rec_exit(char *s)
{
	int cont, len;
	char *_exit = "exit";

	len = _strlen(s);
	cont = 0;
	if (!s)
		return (-1);
	while (s[cont] != '\0')
	{
		if(s[cont] != _exit[cont])
			return (0);
		if(cont == 3 && len == 4)
			return (1);
		cont++;
	}
	return (0);
}

/**
 * free_buf - free the bufo space created by getline - 3
 * @s: message to print before close a proces
 * @len: len of the s
 * @bufo: Addres of bufo
 * Return: void
 */
void free_buf(char *s, int len, char *bufo)
{
	if (s)
		write(STDOUT_FILENO, s, len);
	free(bufo);
	exit(EXIT_FAILURE);
}
/**
 * INThandler - promp with CTRL C - 4
 * @n: none
 * Return: void
 */
void INThandler(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, PROMPT, 9);
}
/**
 * *_strcat - concatenation
 * @dest : det of char
 * @src : source
 * Return: dest the var
 */
char *_strcat(char *dest, char *src)
{
    int n, x, len_dest, len_src;
    char *ret;

    len_dest = _strlen(dest);
    len_src = _strlen(src);
    ret = malloc(sizeof(char) * (len_dest + len_src) + 1);
    for (n = 0; dest[n] != '\0'; n++)
    {
      ret[n] = dest[n];
    }
    for (x = 0 ; src[x] != '\0'; x++, n++)
    {
      ret[n] = src[x];
    }
    ret[n] = '\0';
    return (ret);
}
