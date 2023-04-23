#include "main.h"

int main(void)
{
	int count = 0;

	count = _printf("Hello %s", "world");
	_printf("counted of numbers printed: %d", count);
	return (0);
}
