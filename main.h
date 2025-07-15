#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
int printed = 0;
int size = 0;
int i = 0;
va_list args;
va_start(args, format);

while (format && format[size])
{
if (format[size] == '%')
{
size++;
if (format[size] == 'c')
{
char c = (char)va_arg(args, int);
write(1, &c, 1);
printed++;
}
else if (format[size] == 'd' || format[size] == 'i')
{
int num = va_arg(args, int);
char buffer[12];
i = 0;

if (num == 0)
{
buffer[i++] = '0';
}
else
{
int neg = 0;
if (num < 0)
{
neg = 1;
num = -num; 
}

while (num > 0)
{
buffer[i++] = (num % 10) + '0';
num /= 10;
}
if (neg)
buffer[i++] = '-';
}

int j = 0;  
while (j < i / 2)
{
char tmp = buffer[j];
buffer[j] = buffer[i - j - 1];
buffer[i - j - 1] = tmp;
j++;
}

write(1, buffer, i);
printed += i;
i = 0;
}
else if (format[size] == '%')
{
write(1, "%", 1);
printed++;
}
else
{
}
}
else
{
write(1, &format[size], 1);
printed++;
}
size++;
}

va_end(args);
return printed;
}
#endif /* MAIN_H */
