#include "header.h"

int main()
{
	char *bufo;
	size_t buffosize = 1024;
	int chara;

	bufo = malloc(buffosize * (sizeof(char)));

	if (!bufo)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	do{
		write(STDOUT_FILENO, PROMPT, 11);
		chara = getline(&bufo,&buffosize, stdin);
		if (bufo == "exit")
		{
			free(bufo);
			return(0);
		}
		system(bufo);
		/*printf("Num chars: %d\n",chara);
		  printf("You typed: %s",bufo); */
	} while (chara);


	return(0);
}
