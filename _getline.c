#include "sshell.h"

/**
 * echoer - the function to echo back any text given
 * @lne: array of command and arguments
 *
 * Return: returns one 1 in success and -1 if it fails
 */

int echoer(char *lne[])
{
int i = 1;

if (lne[i] == NULL)
{
write(1, "\n", 2);
return (1);
}

while (lne[i] != NULL)
{
write(1, lne[i], strleng(lne[i]));
i++;
if (lne[i] != NULL)
{
write(1, " ", 2);
}
}
write(1, "\n", 2);

return (1);
}

/**
 * _getline - function to read a line from standard input
 * @lne: pointer to a pointer of location to save the string
 * @len: size of the characters read
 *
 * Return: returns the size of the read string
 */

int _getline(char **lne, size_t *len)
{
size_t limit = 25;
char *temp;

lne[0] = malloc(25);
if (!lne[0])
return (-1);
*len = 0;

while (lne[0][*len - 1] != '\n')
{
lne[0][*len] = _getchar();
*len += 1;

if (*len > (limit - 3))
{
temp = realloc(lne[0], limit + 10);
if (temp)
lne[0] = temp;
else
perror("Reallocation");
limit += 10;
}
}

return (*len);
}

/**
 * _getchar - the function reads a character from standard input
 *
 * Return: returns the read character
 */

char _getchar(void)
{
char *buf;
char d;
int i = 0;

buf = malloc(2);

if (!buf)
return (-1);

fflush(stdout);

i = read(1, buf, 1);
if (i == -1)
{
perror("Reading Char");
return (-1);
}
else if (i == 0)
{
write(1, "\n", 2);
fflush(stdout);
exit(1);
}

d = *buf;

return (d);
}
