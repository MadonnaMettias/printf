#include "main.h"

/**
 * _putchar - a function that prints a single char
 * @c: the char to print
 * Return: 0 always success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _printf - a function that prints output according to a format
 * @format: the format string
 * Return: the numbers of char printed without the null byte.
 */
int _printf(const char *format, ...)
{
	char c, *str;
	int count = 0;
	va_list args;

	va_start(args, format);

	while ((c = *format++) != '\0')
	{
		if (c == '%')
		{
			switch (*++format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					for (str  =va_arg(args, char *); *str != '\0'; str++)
					{
						_putchar(*str);
						count++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
			}
		}
		else
		{
			_putchar(c);
			count++;
		}
	}
	va_end(args);
	return (count);
}
