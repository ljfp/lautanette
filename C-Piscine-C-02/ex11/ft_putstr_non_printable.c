/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:54:05 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/13 01:08:15 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr_non_printable(char *str);
void	print_hex(int c, int depth);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(int c, int depth)
{
	char	*base;

	base = "0123456789abcdef";
	if (c <= 0 && depth == 0)
	{
		c += 256;
	}
	if (c >= 16)
	{
		print_hex(c / 16, 1);
		print_hex(c % 16, 1);
	}
	else
	{
		if (depth == 0)
			ft_putchar('0');
		ft_putchar(base[c]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_putchar('\\');
			j = str[i];
			print_hex(j, 0);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}


int	main(void)
{
	char	*test_string;
	
	test_string = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(test_string);
	ft_putchar('\n'); /* Add newline for clean terminal output */
	
	return (0);
}
