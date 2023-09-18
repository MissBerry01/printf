#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *s);
int print_percent(void);
int print_positive_number(int n);
int print_number(int n);
#endif
