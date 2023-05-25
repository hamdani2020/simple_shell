#ifndef SIMISHELL_H
#define SIMISHELL_H

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;
extern int errno;

/**
 * struct selectfunction - struct array of functions
 * @command: a pointer to the caharacter of command string
 * @funcptr: a pointer to a function
 */

typedef struct selectfunction
{
char *command;
int (*funcptr)(char **line);
} selecte;

char _getchar(void);
char *stringer(char *line, int i, char *str, char c);
int pwder(char *line[]);
int envir(char *line[]);
int maker(char *line[]);
int (*getfunc(char *str))(char **line);
int echorr(char *line[]);
int builtincom(char **line);
int changedire(char **line);
int strleng(char *s);
void strcopy(char *src, char *dest);
int strcomp(char *str, char *equ);
void strmix(char *src, char *dest);
int lister(char **line);
int _getline(char **line, size_t *len);
void farewell(void);
void description(void);
void printstar(void);
void printstr(char *s);
void sigintHandler(int sig_num __attribute__((unused)));
void printprompt(int i);
int exitor(char *line[]);
int cater(char *line[]);
int getstr(char *str);
int shellprocessor(char **line, char **argv);
char **strbrk(char *line, char c);

#endif

