#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
int _printf(const char *format, ...)
{
int size = 0;
int num,i;
char *qaliq,*arrnum;

va_list args;
va_start(args,format);
while(format[size] != '\0')
{
if (format[size] == '%'){
if (format[size + 1] == 'd' || format[size + 1] == 'i'){
write(1,va_arg(args,int),sizeof(va_arg(args,int)));
size++;
}
else if (format[size + 1] == 'c'){
write(1,va_arg(args,char),sizeof(va_arg(args,int)));
size++;
}
else if (format[size + 1] == 'p'){
write(1,va_arg(args,int),sizeof(va_arg(args,int)));
size++;
}
else if (format[size + 1] == 'X' || format[size + 1] == 'x'){
num = va_arg(args,int);
 *arrnum;
i = 0;
 *qaliq = "0123456789abcdef";
while (num > 0)
{
arrnum[i] = num%16;
num = num/16;
i++;
}
num = atoi(arrnum);
write(1,num,sizeof(num));
size++;
}
else if (format[size + 1] == 'O' || format[size + 1] == 'o'){
num = va_arg(args,int);
*arrnum;
i = 0;
 *qaliq = "01234567";
while (num > 0)
{
arrnum[i] = num%8;
num = num/8;
i++;
}
size++;
}
else if (format[size + 1] == 'u'){
write(1,va_arg(args,unsigned int),sizeof(unsigned int));
size++;
}
else if (format[size + 1] == '%'){
writde(1,'%',1);
size++;
}else{
write(1,format[size],1);
}
}
else{
write(1,format[size],1);
}
size++;
}

}

#endif /* MAIN_H */
