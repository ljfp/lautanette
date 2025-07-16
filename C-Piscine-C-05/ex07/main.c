#include <stdio.h>

int	ft_find_next_prime(int nb);
int	ft_is_prime(int nb);
int	ft_sqrt(int nb);

int main(void)
{
    // Test ft_sqrt
    printf("=== Testing ft_sqrt ===\n");
    printf("ft_sqrt(-10) = %d (should be 0)\n", ft_sqrt(-10));
    printf("ft_sqrt(0) = %d (should be 0)\n", ft_sqrt(0));
    printf("ft_sqrt(1) = %d (should be 1)\n", ft_sqrt(1));
    printf("ft_sqrt(4) = %d (should be 2)\n", ft_sqrt(4));
    printf("ft_sqrt(9) = %d (should be 3)\n", ft_sqrt(9));
    printf("ft_sqrt(16) = %d (should be 4)\n", ft_sqrt(16));
    printf("ft_sqrt(24) = %d (should be 4)\n", ft_sqrt(24));
    printf("ft_sqrt(25) = %d (should be 5)\n", ft_sqrt(25));
    
    // Test ft_is_prime
    printf("\n=== Testing ft_is_prime ===\n");
    printf("ft_is_prime(-5) = %d (should be 0)\n", ft_is_prime(-5));
    printf("ft_is_prime(0) = %d (should be 0)\n", ft_is_prime(0));
    printf("ft_is_prime(1) = %d (should be 0)\n", ft_is_prime(1));
    printf("ft_is_prime(2) = %d (should be 1)\n", ft_is_prime(2));
    printf("ft_is_prime(3) = %d (should be 1)\n", ft_is_prime(3));
    printf("ft_is_prime(4) = %d (should be 0)\n", ft_is_prime(4));
    printf("ft_is_prime(5) = %d (should be 1)\n", ft_is_prime(5));
    printf("ft_is_prime(23) = %d (should be 1)\n", ft_is_prime(23));
    printf("ft_is_prime(24) = %d (should be 0)\n", ft_is_prime(24));
    printf("ft_is_prime(97) = %d (should be 1)\n", ft_is_prime(97));
    
    // Test ft_find_next_prime
    printf("\n=== Testing ft_find_next_prime ===\n");
    printf("ft_find_next_prime(-10) = %d (should be 2)\n", ft_find_next_prime(-10));
    printf("ft_find_next_prime(0) = %d (should be 2)\n", ft_find_next_prime(0));
    printf("ft_find_next_prime(1) = %d (should be 2)\n", ft_find_next_prime(1));
    printf("ft_find_next_prime(2) = %d (should be 3)\n", ft_find_next_prime(2));
    printf("ft_find_next_prime(3) = %d (should be 5)\n", ft_find_next_prime(3));
    printf("ft_find_next_prime(4) = %d (should be 5)\n", ft_find_next_prime(4));
    printf("ft_find_next_prime(5) = %d (should be 7)\n", ft_find_next_prime(5));
    printf("ft_find_next_prime(6) = %d (should be 7)\n", ft_find_next_prime(6));
    printf("ft_find_next_prime(10) = %d (should be 11)\n", ft_find_next_prime(10));
    printf("ft_find_next_prime(90) = %d (should be 97)\n", ft_find_next_prime(90));
    printf("ft_find_next_prime(97) = %d (should be 101)\n", ft_find_next_prime(97));
    
    return (0);
}
