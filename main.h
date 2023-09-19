#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
int format_specifier(const char *format, va_list arguments);
int print_char(char c);
int print_string(char *s);
int print_percent(void);
int print_positive_number(int n);
int print_number(int n);
int print_binary(unsigned int n);
int print_unsigned_number(unsigned int n);
int print_octal_number(unsigned int n);
int print_hex_number(unsigned int n, int is_upper);
int print_string_with_escaping(char *s);
int print_hex_ascii_value(char c);
int print_pointer_address(void *ptr);
int print_number(int n, int plus_flag, int space_flag);

#endif
