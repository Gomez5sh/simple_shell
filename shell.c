#include "header.h"

int main()
{
	char *bufo;
	char *dirs[2] = {"/bin/dash", NULL};
	size_t buffosize = 1024;
	int chara;
	pid_t p_id;

	bufo = malloc(buffosize * (sizeof(char)));

	if (!bufo)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	do{
		write(STDOUT_FILENO, PROMPT, 11);
		chara = getline(&bufo, &buffosize, stdin);
		dirs[2] = bufo;
		p_id = fork();
		if (p_id > 0)
		{
			execve(dirs[0], dirs, NULL);
			return (0);

		}
		if (p_id == 0)
		{

		}
		if (p_id < 0)
		{
			/* ERROR MENSAGE */
		}
	} while (chara);


	return(0);
}
