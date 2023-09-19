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
	int printed_characters = 0, num, width;
	unsigned int binary_num, unsigned_num, octal_num, hex_num;
	char *str;
	void *ptr;
	short short_num;
	long long_num;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				return (printed_characters);
			}

			width = 0;
			if (*format >= '0' && *format <= '9')
			{
				while (*format >= '0' && *format <= '9')
				{
					width = width * 10 + (*format - '0');
					format++;
				}
			}

			if (*format == 'c')
				printed_characters += print_char(va_arg(arguments, int));
			else if (*format == 's')
				printed_characters += print_string(va_arg(arguments, char *));
			else if (*format == '%')
				printed_characters += print_percent();

			else if (*format == 'd' || *format == 'i')
			{
				if (format[1] == 'l')
				{
					long_num = va_arg(arguments, long);
					printed_characters += print_positive_long_number(long_num);
				}
				else if (format[1] == 'h')
				{
					short_num = va_arg(arguments, int);
					printed_characters += print_positive_short_number(short_num);
				}
				else
				{
					num = va_arg(arguments, int);
					if (num < 0)
					{
						printed_characters += print_char('-');
						num = -num;
					}
					printed_characters += print_positive_number(num);
				}
			}
			else if (*format == 'b')
			{
				binary_num = va_arg(arguments, unsigned int);
				printed_characters += print_binary(binary_num);
			}
			else if (*format == 'u')
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
			else if (*format == 'S')
			{
				str = va_arg(arguments, char *);
				printed_characters += print_string_with_escaping(str);
			}

			else if (*format == 'p')
			{
				ptr = va_arg(arguments, void *);
				printed_characters += print_pointer_address(ptr);
			}
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
