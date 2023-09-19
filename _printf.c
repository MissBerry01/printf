#include "main.h"
#include "format_specifier2.c"

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
			printed_characters += format_specifier(format, arguments);
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
 * format_specifier - Handles format specifiers
 * @format: Format specifier
 * @arguments: Variable argument list
 * Return: The number of charss printed
 */
int format_specifier(const char *format, va_list arguments)
{
	int printed_characters = 0;
	int num;
	unsigned int binary_num;

	if (*format == 'c')
		printed_characters += print_char(va_arg(arguments, int));
	else if (*format == 's')
		printed_characters += print_string(va_arg(arguments, char *));
	else if (*format == '%')
		printed_characters += print_percent();

	else if (*format == 'd' || *format == 'i')
	{
		num = va_arg(arguments, int);
		if (num < 0)
		{
			printed_characters += print_char('-');
			num = -num;
		}
		printed_characters += print_positive_number(num);
	}
	else if (*format == 'b')
	{
		binary_num = va_arg(arguments, unsigned int);
		printed_characters += print_binary(binary_num);
	}
	else
	{
		printed_characters += print_percent();
		printed_characters += print_char(*format);
	}
	return (printed_characters);
}

/**
 * print_string - Print a string to std output
 * @s: The string to print
 * Return: The number of chars printed
 */
int print_string(char *s)
{
	int printed;

	printed = 0;
	while (*s)
	{
		printed += write(1, s, 1);
		s++;
	}
	return (printed);
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
