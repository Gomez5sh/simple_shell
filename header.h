#ifndef _HEADER_H_
#define _HEADER_H_
#ifndef _GNU_SOURCE_
#define _GNU_SOURCE_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <dirent.h>
#define PROMPT "#Cisfun> "
#define ERROR_MS "shell: No such file or directory\n"

void free_buf(char *s, int len, char*bufo);
int string_rec(char *s);
int _strlen(char *s);
void INThandler(int);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);


#endif
