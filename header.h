#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#define PROMPT "#Cisfun> "
#define ERROR_MS "shell: No such file or directory\n"

void free_buf(char *s, int len, char*bufo);
int string_rec(char *s);
int _strlen(char *s);
#endif
