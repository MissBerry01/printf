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

			printed_characters += format_specifier2(format, arguments);
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
 * format_specifier2 - Handles format specifiers
 * @format: Format specifier
 * @arguments: Variable argument list
 * Return: The number of chars printed
 */
int format_specifier2(const char *format, va_list arguments)
{
	int printed_characters = 0;
	unsigned int unsigned_num, octal_num, hex_num;

	if (*format == 'u')
	{
		unsigned_num = va_arg(arguments, unsigned int);
		printed_characters += print_unsigned_number(unsigned_num);
	}
	else if (*format == 'o')
	{
		octal_num = va_arg(arguments, unsigned int);
		printed_characters += print_octal_number(octal_num);
	}

	else if (*format == 'x' || *format == 'X')
	{
		hex_num = va_arg(arguments, unsigned int);
		printed_characters += print_hex_number(hex_num, *format);
	}
	else
	{
		printed_characters += print_percent();
		printed_characters += print_char(*format);
	}

	return (printed_characters);
}
