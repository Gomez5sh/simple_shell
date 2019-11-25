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
#define PROMPT "#Cisfun> "
#define ERROR_MS "shell: No such file or directory\n"
#define ERROR_PATH "Fail to find PATH\n"

void free_buf(char *s, int len, char*bufo);
int string_rec_exit(char *s);
char *string_rec_path(char *tmp);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
void INThandler(int);
char *findpath(char **env);
int _strcmp(char *tmp);
#endif
