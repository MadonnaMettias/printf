#include "main.h"

/**
*_printf -  a function that produces output according to a format
*@format: a string
*Return: the number of charachres printed excluding the NULL byte.
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char *buffer = malloc(sizeof(char) * 100);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				buffer[count] = va_arg(args, int);
				count++;
			}
			/**
			 *else if (format[i + 1] == 's')
			*{
				*buffer[count] = va_arg(args, char *);
				*count++;
			}*/
			else if (format[i + 1] == '%')
			{
				buffer[count] = '%';
				count++;
			}
	}
	else
	{
		buffer[count] = format[i];
		count++;
	}
	}
	va_end(args);
	return (count);
}
