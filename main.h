#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define S_LONG 2
#define S_SHORT 1
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - Struct op
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/**
 * isprintable - check if a char is printable
 */
int isprintable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascii in hexadecimal code to buffer
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * isdigit - check if a char is a digit
 */
int isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * numbersizeconvert - Casts a number to the specified value
 * Return: Casted size of num
 */
long int numbersizeconvert(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

//print handlers
int pint(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pbinary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pchar(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pstring(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int ppercent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int poctal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int punsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);


//print uunsupported characters
int unprintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

//Adresses
int ppointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

//handlers
int handleflags(const char *format, int *i);
int handlewidth(const char *format, int *i, va_list list);
int handleprecision(const char *format, int *i, va_list list);
int handlesize(const char *format, int *i);
int writehandle1(char c, char buffer[],
	int flags, int width, int precision, int size);
int handlnumbers(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int bufferhandl1(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int pointerhandl(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

//reversed strings
int preverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int unsgndhandl(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

//useful functions
int isprintable(char);
int append_hexa_code(char, char[], int);
int isdigit(char);

long int numbersizeconvert(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
