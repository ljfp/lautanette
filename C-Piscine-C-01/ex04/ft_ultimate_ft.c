/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:45:21 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/10 22:52:00 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

int main(void)
{
    int a, b;
    
    printf("=== Testing ft_ultimate_div_mod ===\n\n");
    
    // Test case 1: Regular division with remainder
    a = 42;
    b = 10;
    printf("Before: a = %d, b = %d\n", a, b);
    
    ft_ultimate_div_mod(&a, &b);
    
    printf("After: a = %d, b = %d\n", a, b);
    printf("Expected: a = 4, b = 2\n");
    printf("\n");
    
    // Test case 2: Another division with remainder
    a = 15;
    b = 4;
    printf("Before: a = %d, b = %d\n", a, b);
    
    ft_ultimate_div_mod(&a, &b);
    
    printf("After: a = %d, b = %d\n", a, b);
    printf("Expected: a = 3, b = 3\n");
    printf("\n");
    
    // Test case 3: Division without remainder
    a = 20;
    b = 5;
    printf("Before: a = %d, b = %d\n", a, b);
    
    ft_ultimate_div_mod(&a, &b);
    
    printf("After: a = %d, b = %d\n", a, b);
    printf("Expected: a = 4, b = 0\n");
    printf("\n");
    
    // Test case 4: Negative numbers
    a = -15;
    b = 4;
    printf("Before: a = %d, b = %d\n", a, b);
    
    ft_ultimate_div_mod(&a, &b);
    
    printf("After: a = %d, b = %d\n", a, b);
    printf("Expected: a = -3, b = -3\n");
    
    return 0;
}
