#include "includes/ft.h"
#include <stdio.h>

int main(void)
{
    // Test ft_putchar
    printf("Testing ft_putchar: ");
    ft_putchar('A');
    ft_putchar('\n');

    // Test ft_putstr
    printf("Testing ft_putstr: ");
    ft_putstr("Hello, Libft!\n");

    // Test ft_strlen
    char *test_str = "12345";
    printf("Testing ft_strlen: ");
    int len = ft_strlen(test_str);
    printf("Length of \"%s\" is %d\n", test_str, len);

    // Test ft_strcmp
    printf("Testing ft_strcmp:\n");
    printf("Compare \"abc\" and \"abc\": %d\n", ft_strcmp("abc", "abc")); // Should be 0
    printf("Compare \"abc\" and \"abd\": %d\n", ft_strcmp("abc", "abd")); // Should be negative
    printf("Compare \"abd\" and \"abc\": %d\n", ft_strcmp("abd", "abc")); // Should be positive

    // Test ft_swap
    int x = 10, y = 20;
    printf("Testing ft_swap:\n");
    printf("Before swap: x = %d, y = %d\n", x, y);
    ft_swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}
