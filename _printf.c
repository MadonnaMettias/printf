#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}


/**
 *print_num - a function that print an int.
 *@n: the int to print
 *Return: the numbers of charachter printed
 */
int print_num(int n)
{
	int count = 0;

	if (n / 10)
		count += print_num(n / 10);
	_putchar((n % 10) + '0');
	count++;
	return (count);
}

/**
 * _printf - prints output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;

	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = (char) va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				while (*s)
				{
					_putchar(*s);
					count++;
					s++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int n = va_arg(args, int);

				if (n < 0)
				{
					_putchar('-');
					count++;
					n = -n;
				}	
				count += print_num(n);
			}
			else if (*format == 'b')
			{
				unsigned int n = va_arg(args, unsigned int);
				count += print_bin(n)
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
