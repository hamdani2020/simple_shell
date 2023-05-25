#include "sshell.h"

/**
* echorr - the function which echo back any text
* @lne: array of command and arguments
*
* Return: returns one 1 in success and -1 if it fails
*/

int echorr(char *lne[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking");
}
if (child == 0)
{
execve("/bin/echo", lne, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
{
perror("Waiting");
}
}
free(lne);

return (1);
}

/**
* pwder - function which prints current path
* @lne: array of command and arguments
*
* Return: returns one 1 in success and -1 if it fails
*/

int pwder(char *lne[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
perror("Forking");

if (child == 0)
{
execve("/bin/pwd", lne, NULL);
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
* builtincom - the function to excute when unlisted command entered
* @lne: a pointer to pointer of characters
*
* Return: returns an integer
*/

int builtincom(char **lne)
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking");
}

if (child == 0)
{
execve(lne[0], lne, NULL);
if (errno != 0)
{
return (errno);
}
}
else
{
waiter = wait(&status);

if (waiter == -1)
{
perror("Waiting");
}
}

free(lne);
return (0);
}

/**
* cater - a function which excutes the /bin/cat program to show text files
* @lne: an array of command and arguments
*
* Return: returns one 1 in success and neg zero -1 if it fails
*/

int cater(char *lne[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking");
}
if (child == 0)
{
execve("/bin/cat", lne, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
{
perror("Waiting");
}
}
free(lne);

return (1);
}

/**
* lister - function which excutes the /bin/ls program to list files
* @lne: the array of command and arguments
*
* Return: returns one 1 in success and neg zero -1 if it fails
*/

int lister(char *lne[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking");
}

if (child == 0)
{
execve("/bin/ls", lne, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
{
perror("Waiting");
}
}
free(lne);

return (1);
}
