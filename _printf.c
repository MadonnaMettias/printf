#include "main.h"

/**
 * _putchar - a function that prints a char to stdout
 * @c: the char to print
 * Return: 0 always success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - a function that prints a single char
 * @args: a va_list containing the chr to printed
 * @count: a pointer to the count of the printed characters
 */
void print_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	_putchar(c);
	*count += 1;
}

/**
 * print_string - a function that prints a string
 * @args: a va_list containing the string to be printed
 * @count: a pointer to the count of the printed characters
 */
void print_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "NULL";
	while (*str != '\0')
	{
		_putchar(*str);
		*count += 1;
		str++;
	}
}

/**
 * print_percent - print a percent sign.
 * @args: --
 * @count: a pointer to the count of the printed characters
 */
void print_percent(__attribute__((unused)) va_list args, int *count)
{
	_putchar('%');
	count += 1;
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
	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					print_char(args, &count);
					break;
				case 's':
					print_string(args, &count);
					break;
				case '%':
					print_percent(args, &count);
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count += 1;
		}
		format++;
	}
	va_end(args);
	return (count);
}
