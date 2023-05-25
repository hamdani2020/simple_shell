#include "sshell.h"

/**
 * shellprocessor - function which excutes the given commands
 * @lne: pointer to an array of strings
 * @argv: pointer to the array of arguments
 *
 * Return: returns one 1 in success and neg -1 if it fails
 */

int shellprocessor(char **lne, char **argv)
{
int checks;
int i = 0;

if (!lne)
{
return (1); }
if (getfunc(lne[0]) == NULL)
{
i = builtincom(lne);
if (i != 0)
{
for (i = 0; lne[0][i] != '\0'; i++)
{
if (lne[0][i] == '/')
{
checks = 1;
break; }}
if (checks == 1)
{
write(1, argv[0], strleng(argv[0]));
write(1, ": ", 3);
write(1, lne[0], strleng(lne[0]));
write(1, ": No such file or directory\n", 28);
exit(EXIT_FAILURE); }
else
{
write(1, lne[0], strleng(lne[0]));
write(1, ": not found\n", strleng(": not found\n"));
exit(EXIT_FAILURE); }}
}
else
{
getfunc(lne[0])(lne); }
return (1);
}

/**
 * getfunc - function which selects a function based on the commands
 * @str: the command string pointer
 *
 * Return: returns 1 in success and -1 when it fails
 */

int (*getfunc(char *str))(char **line)
{
int j = 0;
selecte selector[] = {
{"ls", lister},
{"l", lister},
{"ll", lister},
{"exit", exitor},
{"echo", echorr},
{"cd", changedire},
{"cat", cater},
{"pwd", pwder},
{"env", envir},
{"printenv", envir},
{"/bin/printenv", envir},
{"/bin/env", envir},
{"mkdir", maker},
{NULL, NULL}};

while (!strcomp(selector[j].command, str) && (selector[j].command != NULL))
{
j++;
}

if (selector[j].command == NULL)
{
return (NULL);
}

return (selector[j].funcptr);
}

