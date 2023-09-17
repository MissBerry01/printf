#include "main.h"
#include <stdio.h>

/**
 * main -test
 * Return: 0 always
 */
int main(void)
{
	int chars_printed;

	chars_printed = _printf("Hello, %s!\n", "world");
	printf("Expected: Hello, world!\n");
	printf("Actual: %d characters printed.\n", chars_printed);

	chars_printed = _printf("The answer is %d\n", 42);
	printf("Expected: The answer is 42\n");
	printf("Actual: %d characters printed.\n", chars_printed);

	return (0);
}
