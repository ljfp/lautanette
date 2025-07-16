#include <stdio.h>

int ft_iterative_power(int nb, int power);

int main(void)
{
    // Basic tests
    printf("2^3 = %d (expected: 8)\n", ft_iterative_power(2, 3));
    printf("3^4 = %d (expected: 81)\n", ft_iterative_power(3, 4));
    printf("5^2 = %d (expected: 25)\n", ft_iterative_power(5, 2));
    
    // Edge cases
    printf("5^0 = %d (expected: 1)\n", ft_iterative_power(5, 0));
    printf("0^0 = %d (expected: 1)\n", ft_iterative_power(0, 0));
    printf("0^5 = %d (expected: 0)\n", ft_iterative_power(0, 5));
    printf("10^-1 = %d (expected: 0)\n", ft_iterative_power(10, -1));
    
    // Negative base
    printf("-2^3 = %d (expected: -8)\n", ft_iterative_power(-2, 3));
    printf("-2^2 = %d (expected: 4)\n", ft_iterative_power(-2, 2));
    
    // Larger values
    printf("10^3 = %d (expected: 1000)\n", ft_iterative_power(10, 3));
    
    return (0);
}
