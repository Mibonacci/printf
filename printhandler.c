#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int index, unknown_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', pchar}, {'s', pstring}, {'%', ppercent},
		{'i', pint}, {'d', pint}, {'b', pbinary},
		{'u', punsigned}, {'o', poctal}, {'p', ppointer}, {'S', unprintable},
		{'r', preverse}, {'\0', NULL}
	};

	for (index = 0; fmt_types[index].fmt != '\0'; index++) {
		if (fmt[*ind] == fmt_types[index].fmt) {
			return (fmt_types[index].fn(list, buffer, flags, width, precision, size));
		}
	}

	if (fmt_types[index].fmt == '\0') {
		if (fmt[*ind] == '\0') {
			return (-1);
		}
		unknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ') {
			unknown_len += write(1, " ", 1);
		}
		else if (width) {
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%') {
				--(*ind);
			}
			if (fmt[*ind] == ' ') {
				--(*ind);
			}
			return (1);
		}
		unknown_len += write(1, &fmt[*ind], 1);
		return (unknown_len);
	}

	return (printed_chars);
}
