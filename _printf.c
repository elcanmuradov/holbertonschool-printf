#include "main.h"

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
