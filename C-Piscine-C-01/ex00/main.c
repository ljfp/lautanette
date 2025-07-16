/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:52:22 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/16 21:26:52 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int	n;

	n = 10;
	printf("Before: number = %d\n", n);
	ft_ft(&n);
	printf("After: number = %d\n", n);
	return (0);
}
