#include "sshell.h"

/**
* printprompt - function to display the enter command character
* @i: an integer value worth indicate which icon to display
*
* Return: void
*/

void printprompt(int i)
{
if (i == 0)
{
write(1, "USH$ ", strleng("USH$ "));
}
else if (i == 1)
{
write(1, "ush> ", strleng("ush> "));
}
}

/**
* changedire - function to change a directory or folder
* @lne: array of commands and arguments
*
* Return: returns zero 0 in success and -1 if it fails
*/

int changedire(char **lne)
{
if (lne[1] == NULL)
{
chdir(getenv("HOME"));
}
else if (chdir(lne[1]) == -1)
{
write(1, lne[0], strleng(lne[0]));
write(1, ": ", 3);
write(1, ": cd", strleng(": cd"));
write(1, ": can't cd to ", strleng(": can't cd to "));
write(1, lne[1], strleng(lne[1]));
write(1, "\n", 2);
return (-1);
}

free(lne);
return (1);
}

/**
* exitor - function to exit from program
* @lne: array of command and arguments
*
* Return: 0
*/

int exitor(char *lne[])
{
int i = 0;
if (lne[1] == NULL)
{
exit(EXIT_SUCCESS); }
else if (atoi(lne[1]) > 0)
{
i = atoi(lne[1]); }
free(lne);
exit(i);
}
