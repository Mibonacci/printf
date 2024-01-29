#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char ch = (char)va_arg(args, int);
                    write(1, &ch, 1);
                    count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str) {
                        write(1, str, 1);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    write(1, "%", 1);
                    count++;
                    break;
                }
                default:
                    break;
            }
        } else {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}

int main() {
    char ch = 'A';
    char *str = "Hello";
    
    int printed = my_printf("Character: %c, String: %s, Percent: %%\n", ch, str);

    // Output the number of characters printed
    my_printf("Number of characters printed: %d\n", printed);

    return 0;
}
