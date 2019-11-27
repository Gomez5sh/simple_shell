#ifndef _HEADER_H_
#define _HEADER_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

#define PROMPT "SHELL "
#define ERROR_MS ": not found\n"
#define ERROR_PATH "Fail to find PATH\n"

extern char **environ;

int _atoi(char *s);
void free_buf(char *s, int len, char *bufo, char *arg);
int string_rec_exit(char *s);
char *string_rec_path(char *tmp);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
void INThandler(int);
char *findpath(char **env, char *to_find);
int _strcmp(char *tmp, char *find);
void change_dir(char *newdir, char *bufo);

#endif
