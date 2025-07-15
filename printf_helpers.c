#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: Character to write
 *
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * print_char - Prints a character
 * @args: va_list containing the character to print
 *
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @args: va_list containing the string to print
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int count = 0;

if (str == NULL)
str = "(null)";

while (*str)
{
_putchar(*str);
str++;
count++;
}

return (count);
}

/**
 * print_percent - Prints a percent sign
 * @args: va_list (unused)
 *
 * Return: Number of characters printed (1)
 */
int print_percent(va_list args)
{
(void)args;
return (_putchar('%'));
}

/**
 * print_int - Prints an integer
 * @args: va_list containing the integer to print
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
int n = va_arg(args, int);
int count = 0;
long num = n;

if (num < 0)
{
_putchar('-');
count++;
num = -num;
}

if (num == 0)
{
_putchar('0');
count++;
}
else
{
char buffer[20];
int i = 0;

while (num > 0)
{
buffer[i] = (num % 10) + '0';
num /= 10;
i++;
}

while (i > 0)
{
i--;
_putchar(buffer[i]);
count++;
}
}

return (count);
}
