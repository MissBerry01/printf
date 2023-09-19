#include "main.h"

/**
 * print_unsigned_number - Print an unsigned
 * @n: The unsigned integer to print
 * Return: The number of characters printed
 */
int print_unsigned_number(unsigned int n)
{
	char buffer[1024];
	int printed = 0;

	if (n == 0)
	{
		return (print_char('0'));
	}

	sprintf(buffer, "%u", n);
	printed += print_string(buffer);

	return (printed);
}

/**
 * print_octal_number - Print an octal number
 * @n: The unsigned integer to print as octal
 * Return: The number of characters printed
 */
int print_octal_number(unsigned int n)
{
	char buffer[1024];
	int printed = 0;

	if (n == 0)
	{
		return (print_char('0'));
	}

	sprintf(buffer, "%o", n);
	printed += print_string(buffer);

	return (printed);
}

/**
 * print_hex_number - Print a hexadecimal number
 * @n: The unsigned integer to print as hexadecimal
 * @is_upper: Whether to print in uppercase (1) or lowercase (0)
 * Return: The number of characters printed
 */

int print_hex_number(unsigned int n, int is_upper)
{
	char buffer[1024];
	int printed = 0;

	if (n == 0)
	{
		return (print_char('0'));
	}

	if (is_upper == 'X')
	{
		sprintf(buffer, "%X", n);
	}

	else
	{
		sprintf(buffer, "%x", n);
	}

	printed += print_string(buffer);

	return (printed);
}
