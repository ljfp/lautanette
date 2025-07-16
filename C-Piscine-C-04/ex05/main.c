#include <stdio.h>

int ft_atoi_base(char *str, char *base);

int main(void)
{
    printf("===== Testing ft_atoi_base =====\n\n");
    
    // Test with decimal base
    printf("Decimal base (0123456789):\n");
    printf("'42': %d\n", ft_atoi_base("42", "0123456789"));
    printf("'-42': %d\n", ft_atoi_base("-42", "0123456789"));
    printf("'  +42': %d\n", ft_atoi_base("  +42", "0123456789"));
    printf("'  -42': %d\n", ft_atoi_base("  -42", "0123456789"));
    printf("'0': %d\n\n", ft_atoi_base("0", "0123456789"));
    
    // Test with binary base
    printf("Binary base (01):\n");
    printf("'101010' (42 in decimal): %d\n", ft_atoi_base("101010", "01"));
    printf("'-101010' (-42 in decimal): %d\n\n", ft_atoi_base("-101010", "01"));
    
    // Test with hexadecimal base
    printf("Hexadecimal base (0123456789ABCDEF):\n");
    printf("'2A' (42 in decimal): %d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
    printf("'FF' (255 in decimal): %d\n", ft_atoi_base("FF", "0123456789ABCDEF"));
    printf("'-FF' (-255 in decimal): %d\n\n", ft_atoi_base("-FF", "0123456789ABCDEF"));
    
    // Test with octal base
    printf("Octal base (01234567):\n");
    printf("'52' (42 in decimal): %d\n\n", ft_atoi_base("52", "01234567"));
    
    // Test with custom base
    printf("Custom base (poneyvif):\n");
    printf("'ey' (28 in decimal): %d\n\n", ft_atoi_base("ey", "poneyvif"));
    
    // Test with spaces and signs
    printf("With spaces and signs:\n");
    printf("'  \\t\\n-+--2A' (in hex): %d\n\n", ft_atoi_base("  \t\n-+--2A", "0123456789ABCDEF"));
    
    // Test error cases
    printf("Error cases (should return 0):\n");
    printf("Empty base: %d\n", ft_atoi_base("42", ""));
    printf("One character base: %d\n", ft_atoi_base("42", "0"));
    printf("Base with duplicate chars: %d\n", ft_atoi_base("42", "01234567890"));
    printf("Base with + sign: %d\n", ft_atoi_base("42", "0123+56789"));
    printf("Base with - sign: %d\n", ft_atoi_base("42", "0123-56789"));
    printf("Base with space: %d\n", ft_atoi_base("42", "0123 56789"));
    
    return 0;
}
