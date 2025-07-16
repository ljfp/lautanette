/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:57:50 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/16 21:28:42 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	x;
	int	y;

	x = 10;
	y = 20;
	printf("Initial values: x = %d, y = %d\n", x, y);
	ft_swap(&x, &y);
	printf("After ft_swap: x = %d, y = %d\n", x, y);
	return (0);
}
