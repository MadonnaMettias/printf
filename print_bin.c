/**
 * print_bin - a function that prints an int in binary.
 * @n: the int to print.
 * Return: the numbers of characters printed.
 */
int print_bin(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += print_bin(n / 2);
	_putchar((n % 2) + '0');
	count++;
	return (count);
}
