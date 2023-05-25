#include "sshell.h"

/**
 * printstr - a function to print a given string between a stars
 * @x: a string location pointer
 *
 * Return: void
 */

void printstr(char *x)
{
int len = strleng(x), spec, n = 0;

write(1, "\n\t\t\t***\t", strleng("\n\t\t\t***\t"));

spec = (60 - len) / 2;

while (n < spec)
{
write(1, " ", 2);
n++;
}

write(1, x, strleng(x));

while (n > 0)
{
write(1, " ", 2);
n--;
}

write(1, "\t***", strleng("\t***"));
}

/**
 * printstar - prints star line
 *
 * Return: void
 */

void printstar(void)
{
int j = 0;
write(1, "\n\t\t\t", 5);

while (j < 75)
{
write(1, "*", 2);
j++;
}
}

/**
 * description -  function to discription about the program
 *
 * Return: void
 */

void description(void)
{
printstar();
printstar();
printstr("~- H.E.L.L.O _ W.A.R.M.L.Y _ W.E.L.C.O.M.E -~");
printstr("");
printstr("This is a simple unix shell project.");
printstr("Designed by Alhassan Hamdani and Shamuna for ALX SE ");
printstr("https://github.com/hamdani2020");
printstar();
printstar();
}

/**
 * strcomp - a function that compares two strings
 * @str: the initial string to be compared
 * @eq: the second string to comapre too
 *
 * Return: returns integer indicater of the boolean
 */

int strcomp(char *str, char *eq)
{
int i = 0;
int result = 0;

if (str == NULL || eq == NULL)
{
return (0);
}
while (eq[i] != '\0' || str[i] != '\0')
{

if (str[i] == eq[i])
{
result = 1;
}
else
{
result = 0;
}
i++;
}

return (result);
}
