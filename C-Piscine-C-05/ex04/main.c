#include <stdio.h>

int ft_fibonacci(int index);

int main(void)
{
    // Error case
    printf("Fibonacci(-1) = %d (expected: -1)\n", ft_fibonacci(-1));
    
    // Base cases
    printf("Fibonacci(0) = %d (expected: 0)\n", ft_fibonacci(0));
    printf("Fibonacci(1) = %d (expected: 1)\n", ft_fibonacci(1));
    
    // First few Fibonacci numbers
    printf("Fibonacci(2) = %d (expected: 1)\n", ft_fibonacci(2));
    printf("Fibonacci(3) = %d (expected: 2)\n", ft_fibonacci(3));
    printf("Fibonacci(4) = %d (expected: 3)\n", ft_fibonacci(4));
    printf("Fibonacci(5) = %d (expected: 5)\n", ft_fibonacci(5));
    printf("Fibonacci(6) = %d (expected: 8)\n", ft_fibonacci(6));
    printf("Fibonacci(7) = %d (expected: 13)\n", ft_fibonacci(7));
    
    // Slightly larger values
    printf("Fibonacci(10) = %d (expected: 55)\n", ft_fibonacci(10));
    printf("Fibonacci(15) = %d (expected: 610)\n", ft_fibonacci(15));
    
    return (0);
}
