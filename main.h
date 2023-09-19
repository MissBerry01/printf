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
int format_specifier2(const char *format, va_list arguments);

#endif
