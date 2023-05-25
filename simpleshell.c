#include "sshell.h"

/**
 * main - main function of the simple shell
 * @argc: number of arguments given
 * @argv: array of given argument strings
 *
 * Return: returns integer
 */

int main(int argc __attribute__((unused)), char **argv)
{
char *lne;

lne = malloc(256);
if (!lne)
{
perror("Allocation");
exit(1);
}

if (!isatty(STDIN_FILENO))
{
if (getstr(lne) == (-1))
{
write(1, "\n", 2);
exit(1);
}
if (shellprocessor(strbrk(lne, ' '), argv) == -1)
{
perror("Error");
}

exit(0);
}

do {
printprompt(0);
if (getstr(lne) == (-1))
{
write(1, "\n", 2);
exit(0);
}

if ((shellprocessor(strbrk(lne, ' '), argv)) == -1)
{
perror("Error");
}
} while (1);

return (0);
}

/**
 * sigintHandler - function to handle the Ctrl-C signal
 * @sig_num: integer signal indicator
 *
 * Return: void function
 */

void sigintHandler(int sig_num __attribute__((unused)))
{
signal(SIGINT, sigintHandler);
write(1, "\n", 2);
printprompt(0);
fflush(stdout);
}

/**
 * copyarray - function to copy string array to another string array variable
 * @lne: string array to be copied
 * 
 * Return: returns copied array
 */

char **copyarray(char **lne)
{
char **arrays;
int i = 1;

arrays = malloc(64);
if (!arrays)
return (NULL);

while (lne[i] != NULL)
{
arrays[(i - 1)] = malloc(32);
if (!arrays[(i - 1)])
return (NULL);

strcopy(lne[i], arrays[(i - 1)]);
i++;
}

return (arrays);
}


