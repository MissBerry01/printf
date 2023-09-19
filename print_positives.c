#include "main.h"

/**
 * print_positive_number - Print a positive integer to std output
 * @n: The positive integer to print
 * Return: The number of characters printed
 */
int print_positive_number(int n)
{
	int printed = 0;

	if (n == 0)
	{
		return (print_char('0'));
	}

	if (n / 10 != 0)
	{
		printed += print_positive_number(n / 10);
	}
	printed += print_char((n % 10) + '0');
	return (printed);
}
/**
 * print_number - Print a signed integer to std output
 * @n: The integer to print
 * Return: The number of characters printed
 */
int print_number(int n)
{
	int printed;

	if (n < 0)
	{

		printed = 0;
		printed += print_char('-');
		printed += print_positive_number(-n);
		
		return (printed);
	}
	else
	{
		return (print_positive_number(n));
	}
}

/**
 * print_pointer_address - Print a pointer address
 * @ptr: The pointer to print
 * Return: The number of chars printed
 */

int print_pointer_address(void *ptr)
{
	char buffer[1024];
	int printed = 0;

	sprintf(buffer, "%p", ptr);
	printed += print_string(buffer);

	return (printed);
}
