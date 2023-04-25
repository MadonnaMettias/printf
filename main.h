#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int _strlen(char *s);
void print_char(va_list args, int *count);
void print_string(va_list args, int *count);
void print_percent(__attribute__((unused)) va_list args, int *count);
int _putchar(char c);
void print_num(va_list args, int *count);
int print_bin(unsigned int n);
int _printf(const char *format, ...);

#endif
