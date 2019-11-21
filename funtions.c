#include "header.h"
/**
 * _strlen - Count char
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
 * string_rec - funtion recognize the string arg when ir a call system funtion
 * @s: string arg
 * Return: (0)none (1)exit
 */
int string_rec(char *s)
{
	int cont, len;
	char *_exit = "exit";

	len = _strlen(s);
	cont = 0;
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
 * free_buf - free the bufo space created by getline
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
