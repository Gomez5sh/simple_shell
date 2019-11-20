#ifndef HEADER_H
#define HEADER_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#define PROMPT "#Cisfun> "
#define ERROR_MS "shell: No such file or directory\n"

char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);

#endif
