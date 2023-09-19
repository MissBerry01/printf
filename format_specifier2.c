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

/**
 * print_string_with_escaping - Print a string with escaping char
 * @s: The string to print
 * Return: The number of chars printed
 */

int print_string_with_escaping(char *s)
{
	int printed = 0;

	while (*s)
	{
		if (*s >= 32 && *s < 127)
		{
			printed += print_char(*s);
		}
		else
		{
			printed += print_char('\\');
			printed += print_char('x');
			printed += print_hex_ascii_value(*s);
		}
		s++;
	}
	return (printed);
}

/**
 * print_hex_ascii_value - Print the hexadecimal ASCII
 * @c: The character to print
 * Return: The number of chars printed
 */

int print_hex_ascii_value(char c)
{
	char hex_digits[] = "0123456789ABCDEF";
	int printed = 0;

	printed += print_char(hex_digits[(c >> 4) & 0xF]);
	printed += print_char(hex_digits[c & 0xF]);
	return (printed);
}
