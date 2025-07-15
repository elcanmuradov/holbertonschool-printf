#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

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
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 *
 * Description: Produces output according to a format string
 * Handles conversion specifiers: c, s, %
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;

if (format == NULL)
return (-1);

va_start(args, format);

while (format[i])
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
{
va_end(args);
return (-1);
}

if (format[i] == 'c')
count += print_char(args);
else if (format[i] == 's')
count += print_string(args);
else if (format[i] == '%')
count += print_percent(args);
else
{
_putchar('%');
_putchar(format[i]);
count += 2;
}
}
else
{
_putchar(format[i]);
count++;
}
i++;
}

va_end(args);
return (count);
}

#endif /* MAIN_H */
