#include "shell.h"

int main()
{
	char *bufo;
	size_t buffosize = 1024;
	size_t chara;

	bufo = malloc(buffosize * 1);

	if (!bufo)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	printf("#CISFUN$ ");
    chara = getline(&bufo,&buffosize, stdin);
    printf("%zu characters were read.\n",chara);
    printf("You typed: '%s'\n",bufo);

    return(0);
}
