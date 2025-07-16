/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:54:05 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/16 21:36:02 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	*test_string;
	
	test_string = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(test_string);
	ft_putchar('\n');
	
	return (0);
}
