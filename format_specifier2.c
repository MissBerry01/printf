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
