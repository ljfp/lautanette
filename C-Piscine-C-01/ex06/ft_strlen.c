/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:29:09 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/11 12:39:20 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}

int	main(void)
{
	char	*str;
	int		len;
	char	len_to_char;

	str = "123456789";
	len = ft_strlen(str);
	len_to_char = '0' + len;
	write(1, &len_to_char, 1);
	return (0);
}
