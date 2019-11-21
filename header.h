<<<<<<< HEAD
#ifndef _HEADER_H_
#define _HEADER_H_

=======
#ifndef HEADER_H
#define HEADER_H
#define _GNU_SOURCE
>>>>>>> 73bb02bf6230650ee1721adb63de20de83df1464
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#define PROMPT "#Cisfun> "
#define ERROR_MS "shell: No such file or directory\n"

<<<<<<< HEAD
void free_buf(char *s, int len, char*bufo);
int string_rec(char *s);
int _strlen(char *s);
=======
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);

>>>>>>> 73bb02bf6230650ee1721adb63de20de83df1464
#endif
