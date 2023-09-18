#include "main.h"

/**
 * _printf - Prints formatted text into the std output
 * @format: string with the format specifiers
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int printed_characters = 0;

	va_list arguments;

	va_start(arguments, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				break;
			}

			if (*format == 'c')
				printed_characters += print_char(va_arg(arguments, int));
			else if (*format == 's')
				printed_characters += print_string(va_arg(arguments, char *));
			else if (*format == '%')
				printed_characters += print_percent();
			else
			{
				printed_characters += print_percent();
				printed_characters += print_char(*format);
			}
		}
		else
		{
			printed_characters += print_char(*format);
		}

		format++;
	}
	va_end(arguments);

	return (printed_characters);
}

/**
 * print_string - Print a string to std output
 * @s: The string to print
 * Return: The number of chars printed
 */
int print_string(char *s)
{
	int print = 0;

	while (*s)
	{
		print += write(1, s, 1);
		s++;
	}
	return (print);
}

/**
 * print_char - Print a single char to std output
 * @c: The character to print
 * Return: The number of chars printed
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_percent - Print a percent sign to std output
 * Return: The number of chars printed
 */

int print_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * print_positive_number - Print a positive integer to std output
 * @n: The positive integer to print
 * Return: The number of characters printed
 */
int print_positive_number(int n)
{
	int printed = 0;

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
	if (n < 0)
	{
		int printed = 0;

		printed += print_char('-');
		printed += print_positive_number(-n);
		return (printed);
	}
	else
	{
		return (print_positive_number(n));
	}
}
