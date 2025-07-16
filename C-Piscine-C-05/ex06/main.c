#include <stdio.h>

int	ft_is_prime(int nb);
int	ft_sqrt(int nb);

int	main(void)
{
	printf("Testing ft_sqrt function:\n");
	printf("-----------------------\n");
	printf("ft_sqrt(0) = %d (Expected: 0)\n", ft_sqrt(0));
	printf("ft_sqrt(1) = %d (Expected: 1)\n", ft_sqrt(1));
	printf("ft_sqrt(4) = %d (Expected: 2)\n", ft_sqrt(4));
	printf("ft_sqrt(9) = %d (Expected: 3)\n", ft_sqrt(9));
	printf("ft_sqrt(16) = %d (Expected: 4)\n", ft_sqrt(16));
	printf("ft_sqrt(24) = %d (Expected: 4)\n", ft_sqrt(24));
	printf("ft_sqrt(25) = %d (Expected: 5)\n", ft_sqrt(25));
	printf("ft_sqrt(2147395600) = %d (Expected: 46340)\n", ft_sqrt(2147395600));
	
	printf("\nTesting ft_is_prime function:\n");
	printf("--------------------------\n");
	printf("ft_is_prime(-7) = %d (Expected: 0)\n", ft_is_prime(-7));
	printf("ft_is_prime(0) = %d (Expected: 0)\n", ft_is_prime(0));
	printf("ft_is_prime(1) = %d (Expected: 0)\n", ft_is_prime(1));
	printf("ft_is_prime(2) = %d (Expected: 1)\n", ft_is_prime(2));
	printf("ft_is_prime(3) = %d (Expected: 1)\n", ft_is_prime(3));
	printf("ft_is_prime(4) = %d (Expected: 0)\n", ft_is_prime(4));
	printf("ft_is_prime(5) = %d (Expected: 1)\n", ft_is_prime(5));
	printf("ft_is_prime(6) = %d (Expected: 0)\n", ft_is_prime(6));
	printf("ft_is_prime(7) = %d (Expected: 1)\n", ft_is_prime(7));
	printf("ft_is_prime(11) = %d (Expected: 1)\n", ft_is_prime(11));
	printf("ft_is_prime(12) = %d (Expected: 0)\n", ft_is_prime(12));
	printf("ft_is_prime(13) = %d (Expected: 1)\n", ft_is_prime(13));
	printf("ft_is_prime(25) = %d (Expected: 0)\n", ft_is_prime(25));
	printf("ft_is_prime(29) = %d (Expected: 1)\n", ft_is_prime(29));
	printf("ft_is_prime(97) = %d (Expected: 1)\n", ft_is_prime(97));
	printf("ft_is_prime(100) = %d (Expected: 0)\n", ft_is_prime(100));
	printf("ft_is_prime(101) = %d (Expected: 1)\n", ft_is_prime(101));
	
	return (0);
}
