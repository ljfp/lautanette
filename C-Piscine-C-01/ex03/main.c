/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:30:38 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/16 21:28:54 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
    int a, b;
    int division_result;
    int remainder;
    
    printf("=== Testing ft_div_mod ===\n\n");
    
    // Test case 1: Regular division with remainder
    a = 42;
    b = 10;
    printf("Before: a = %d, b = %d\n", a, b);
    printf("Before: division_result = (uninitialized), remainder = (uninitialized)\n");
    ft_div_mod(a, b, &division_result, &remainder);
    printf("After: division_result = %d, remainder = %d\n", division_result, remainder);
    printf("Expected: division_result = 4, remainder = 2\n");
    printf("\n");
    
    // Test case 2: Another division with remainder
    a = 15;
    b = 4;
    printf("Before: a = %d, b = %d\n", a, b);
    printf("Before: division_result = %d, remainder = %d\n", division_result, remainder);
    ft_div_mod(a, b, &division_result, &remainder);
    printf("After: division_result = %d, remainder = %d\n", division_result, remainder);
    printf("Expected: division_result = 3, remainder = 3\n");
    printf("\n");
    
    // Test case 3: Division without remainder
    a = 20;
    b = 5;
    printf("Before: a = %d, b = %d\n", a, b);
    printf("Before: division_result = %d, remainder = %d\n", division_result, remainder);
    ft_div_mod(a, b, &division_result, &remainder);
    printf("After: division_result = %d, remainder = %d\n", division_result, remainder);
    printf("Expected: division_result = 4, remainder = 0\n");
    printf("\n");
    
    // Test case 4: Negative numbers
    a = -15;
    b = 4;
    printf("Before: a = %d, b = %d\n", a, b);
    printf("Before: division_result = %d, remainder = %d\n", division_result, remainder);
	ft_div_mod(a, b, &division_result, &remainder);
	printf("After: division_result = %d, remainder = %d\n", division_result, remainder);
	printf("Expected: division_result = -3, remainder = -3\n");

	return (0);
}
