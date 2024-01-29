#include"main.h"


int main() {
    char ch = 'A';
    char *str = "Hello";
    
    int printed = my_printf("Character: %c, String: %s, Percent: %%\n", ch, str);

    // Output the number of characters printed
    my_printf("Number of characters printed: %d\n", printed);

    return 0;
}