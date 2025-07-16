#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ft_sqrt(int nb);

int main(void)
{
    // Test perfect squares
    printf("Perfect squares:\n");
    printf("ft_sqrt(0) = %d (expected: 0)\n", ft_sqrt(0));
    printf("ft_sqrt(1) = %d (expected: 1)\n", ft_sqrt(1));
    printf("ft_sqrt(4) = %d (expected: 2)\n", ft_sqrt(4));
    printf("ft_sqrt(9) = %d (expected: 3)\n", ft_sqrt(9));
    printf("ft_sqrt(16) = %d (expected: 4)\n", ft_sqrt(16));
    printf("ft_sqrt(25) = %d (expected: 5)\n", ft_sqrt(25));
    printf("ft_sqrt(100) = %d (expected: 10)\n", ft_sqrt(100));
    printf("ft_sqrt(10000) = %d (expected: 100)\n", ft_sqrt(10000));
    
    // Test non-perfect squares
    printf("\nNon-perfect squares:\n");
    printf("ft_sqrt(2) = %d (expected: 0)\n", ft_sqrt(2));
    printf("ft_sqrt(3) = %d (expected: 0)\n", ft_sqrt(3));
    printf("ft_sqrt(10) = %d (expected: 0)\n", ft_sqrt(10));
    printf("ft_sqrt(99) = %d (expected: 0)\n", ft_sqrt(99));
    printf("ft_sqrt(2147395600) = %d (expected: 46340)\n", ft_sqrt(2147395600));
    printf("ft_sqrt(2147483647) = %d (expected: 0)\n", ft_sqrt(2147483647));
    
    // Test negative numbers
    printf("\nNegative numbers:\n");
    printf("ft_sqrt(-1) = %d (expected: 0)\n", ft_sqrt(-1));
    printf("ft_sqrt(-16) = %d (expected: 0)\n", ft_sqrt(-16));
    
    return 0;
}
