#include "main.h"

/**
 * _strlen - a function that return the legnth of a string
 * @s: a string
 * Return: the legnth of the string
 */
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}


/**
 * _printf - a function that prints output according to a format
 * @format: the format string
 * Return: the numbers of char printed without the null byte.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			switch (*++format)
			{
				case 'c':
					{
						char c = va_arg(args, int);

						write(1, &c, 1);
						count++;
						break;
					}
				case 's':
					{
						char *s = va_arg(args, char *);

						write(1, s, _strlen(s));
						count += _strlen(s);
						break;
					}
				case '%':
					{
						write(1, "%", 1);
						count++;
						break;
					}
				default:
					{
						break;
					}
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

