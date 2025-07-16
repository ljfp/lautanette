#include <stdio.h>
#include <limits.h>

int		base_error(char *base);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putchar(char c);

int main(void)
{
    printf("===== Testing ft_putnbr_base =====\n\n");
    
    // Test with decimal base
    printf("Decimal base (0123456789):\n");
    printf("42: ");
    fflush(stdout); // Add this before calling ft_putnbr_base
    ft_putnbr_base(42, "0123456789");
    printf("\n");
    
    printf("-42: ");
    fflush(stdout);
    ft_putnbr_base(-42, "0123456789");
    printf("\n");
    
    printf("0: ");
    fflush(stdout);
    ft_putnbr_base(0, "0123456789");
    printf("\n\n");
    
    // Test with binary base
    printf("Binary base (01):\n");
    printf("42: ");
    fflush(stdout);
    ft_putnbr_base(42, "01");
    printf(" (expected: 101010)\n");
    
    printf("-42: ");
    fflush(stdout);
    ft_putnbr_base(-42, "01");
    printf(" (expected: -101010)\n\n");
    
    // Test with hexadecimal base
    printf("Hexadecimal base (0123456789ABCDEF):\n");
    printf("42: ");
    fflush(stdout);
    ft_putnbr_base(42, "0123456789ABCDEF");
    printf(" (expected: 2A)\n");
    
    printf("255: ");
    fflush(stdout);
    ft_putnbr_base(255, "0123456789ABCDEF");
    printf(" (expected: FF)\n");
    
    printf("-255: ");
    fflush(stdout);
    ft_putnbr_base(-255, "0123456789ABCDEF");
    printf(" (expected: -FF)\n\n");
    
    // Test with octal base
    printf("Octal base (01234567):\n");
    printf("42: ");
    fflush(stdout);
    ft_putnbr_base(42, "01234567");
    printf(" (expected: 52)\n\n");
    
    // Test with custom base
    printf("Custom base (poneyvif):\n");
    printf("42: ");
    fflush(stdout);
    ft_putnbr_base(42, "poneyvif");
    printf(" (expected: ey)\n\n");
    
    // Test edge cases
    printf("Edge cases:\n");
    printf("INT_MAX: ");
    fflush(stdout);
    ft_putnbr_base(INT_MAX, "0123456789");
    printf(" (expected: 2147483647)\n");
    
    printf("INT_MIN: ");
    fflush(stdout);
    ft_putnbr_base(INT_MIN, "0123456789");
    printf(" (expected: -2147483648)\n\n");
    
    // Test error cases
    printf("Error cases (should not output anything):\n");
    
    printf("Empty base: ");
    fflush(stdout);
    ft_putnbr_base(42, "");
    printf(" (no output expected)\n");
    
    printf("One character base: ");
    fflush(stdout);
    ft_putnbr_base(42, "0");
    printf(" (no output expected)\n");
    
    printf("Base with duplicate chars: ");
    fflush(stdout);
    ft_putnbr_base(42, "01234567890");
    printf(" (no output expected)\n");
    
    printf("Base with + sign: ");
    fflush(stdout);
    ft_putnbr_base(42, "0123+56789");
    printf(" (no output expected)\n");
    
    printf("Base with - sign: ");
    fflush(stdout);
    ft_putnbr_base(42, "0123-56789");
    printf(" (no output expected)\n");
    
    return 0;
}
