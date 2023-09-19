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

/**
 * print_long_number - Print a long integer to std output
 * @n: The long integer to print
 * Return: The number of characters printed
 */

int print_long_number(long n)
{
	int printed = 0;

	if (n < 0)
	{
		printed += print_char('-');
		n = -n;
	}

	printed += print_positive_long_number(n);

	return (printed);
}

/**
 * print_positive_long_number - Print a positive long integer
 * @n: The positive long integer to print
 * Return: The number of characters printed
 */

int print_positive_long_number(long n)
{
	int printed = 0;

	if (n / 10 != 0)
	{
		printed += print_positive_long_number(n / 10);
	}

	printed += print_char((n % 10) + '0');
	return (printed);
}

/**
 * print_short_number - Print a short integer to std output
 * @n: The short integer to print
 * Return: The number of characters printed
 */

int print_short_number(short n)
{
	int printed = 0;

	if (n < 0)
	{
		printed += print_char('-');
		n = -n;
	}

	printed += print_positive_short_number(n);

	return (printed);
}

/**
 * print_positive_short_number - Print a positive short integer
 * @n: The positive short integer to print
 * Return: The number of characters printed
 */

int print_positive_short_number(short n)
{
	int printed = 0;

	if (n / 10 != 0)
	{
		printed += print_positive_short_number(n / 10);
	}

	printed += print_char((n % 10) + '0');

	return (printed);
}
