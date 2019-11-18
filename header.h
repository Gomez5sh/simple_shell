#ifndef SHELL_H
#define SHELL_H
#define PROMPT "#ShellFun$ "

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>


int main();
void lsh_loop(void);

#endif
