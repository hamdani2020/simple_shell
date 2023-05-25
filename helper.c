#include "sshell.h"

/**
 * stringer - a helper function to the string breaker
 * @lne: a pointer
 * @i: an index of the start of the string
 * @str: string pointer to a location
 * @d: character which specifies where to end the string
 *
 * Return: returns string pointer
 */

char *stringer(char *lne, int i, char *str, char d)
{
int j = 0;
char *tmp;

str = malloc(64);
if (str == NULL)
{
perror("Couldn't Allocate");
return (NULL);
}
while (lne[i] != d && lne[i] != '\0')
{
str[j] = lne[i++];
j++;
if (j > 60)
{
tmp = realloc(str, (j + 8));
if (!tmp)
{
perror("Error");
return (NULL);
}
else
str = tmp;
}
}

str[j] = '\0';

return (str);
}

/**
 * maker - a function which excutes the /bin/ls program to list files
 * @lne: an array of command and arguments
 *
 * Return: returns 1 in success and -1 if it fails
 */

int maker(char *lne[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
perror("Forking");

if (child == 0)
{
execve("/bin/mkdir", lne, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
perror("Waiting");
}
free(lne);
return (1);
}

/**
 * envir - function which excutes the /bin/ls program to list files
 * @lne: array of command and arguments
 *
 * Return: returns one  1 in success and neg -1 if it fails
 */

int envir(char *lne[] __attribute__((unused)))
{
int i = 0;

while (environ[i] != NULL)
{
write(1, environ[i], strleng(environ[i]));
write(1, "\n", 2);
i++;
}
free(lne);
return (1);
}
