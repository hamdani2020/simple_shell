#include "sshell.h"

/**
* strleng - measures length of string
* @x: string location pointer
*
* Return: returns the length
*/

int strleng(char *x)
{
int len = 0;

while (x[len] != '\0')
{
len++;
}

return (len);
}

/**
* strbrk - function breaks a long string in to array of strings
* @lne: string to breakdown
* @d: character specifier where to break the string
*
* Return: returns the array of words.
*/

char **strbrk(char *lne, char d)
{
int i = 0, j = 0;
char **array, **tmp;

if (!lne || lne[0] == '\0')
{
return (NULL);
}
array = malloc(sizeof(*array) * 128);
if (array == NULL)
{
perror("Couldn't Allocate");
return (NULL); }
while (lne[i] != '\0')
{
if (j > 124)
{
tmp = realloc(array, sizeof(*array) * (i + 4));
if (tmp == NULL)
{
perror("Couldn't Reallocate");
return (NULL); }
else
{
array = tmp; }
}
if (lne[i] == d)
{
i++;
continue; }
array[j] = stringer(lne, i, array[j], d);
if (array[j] == NULL)
{
return (NULL); }
i += strleng(array[j++]);
}
array[j] = NULL;
return (array);
}

/**
* strmix - a function to copy to strings and concatenate if
*	   the destination have a string already.
* @src: the string to be copied
* @des: the destination of the copied string
*
* Return: returns nothing (void)
*/

void strmix(char *src, char *des)
{
int i = 0;
int h;

if (!des)
{
h = 0;
}
else
{
h = strleng(des);
}

while (src[i] != '\0' && src[i] != '\n')
{
des[h++] = src[i++];
}

des[h] = '\0';
}

/**
* strcopy - a function to copy to strings
* @src: the string to be copied
* @des: the destination of the copied string
*
* Return: returns nothing (void)
*/

void strcopy(char *src, char *des)
{
int i = 0;
int h = 0;

if (!des)
{
h = 0;
}

while (src[i] != '\0' && src[i] != '\n')
{
des[h++] = src[i++];
}

des[h] = '\0';
}

/**
* getstr - function to read a string from  the cli
* @str: string pointer
*
* Return: return 1 when it succeeds and -1 in failure
*/

int getstr(char *str)
{
char **lne;
size_t siz = 0;
signal(SIGINT, sigintHandler);
lne = malloc(24);
if (!lne)
{
return (-1);
}

if ((getline(lne, &siz, stdin)) == -1)
{
return (-1);
}

lne[0][siz] = '\0';

strcopy(lne[0], str);

if (lne[0][siz - 2] == '\\')
{
do {
str[strleng(str) - 1] = ' ';
siz = 0;
printprompt(1);

if ((getline(lne, &siz, stdin)) == -1)
{
return (-1);
}
lne[0][siz] = '\0';

strmix(lne[0], str);
} while (lne[0][siz - 2] == '\\');
}

free(lne);
return (1);
}

