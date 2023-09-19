#include "main.h"

/**
 * print_binary - Print an unsigned integer
 * @n: The unsigned integer to print
 * Return: The number of characters printed
 */

int print_binary(unsigned int n)
{
	int printed = 0, idx, i;
	char binary_buffer[32];

	if (n == 0)
	{
		printed += print_char('0');
		return (printed);
	}

	idx = 0;
	while (n > 0)
	{
		binary_buffer[idx] = (n % 2) + '0';
		n /= 2;
		idx++;
	}

	for (i = idx - 1; i >= 0; i--)
	{
		printed += print_char(binary_buffer[i]);
	}

	return (printed);
}
