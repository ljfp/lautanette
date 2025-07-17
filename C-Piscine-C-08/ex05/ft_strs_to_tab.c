/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:17:33 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/17 14:43:53 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str);
char				*ft_strdup(char *src);
static void			ft_free_stock(struct s_stock_str *stock, int count);
static void			as(struct s_stock_str *s, int size, char *str, char *copy);
struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

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

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	ft_free_stock(struct s_stock_str *stock, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(stock[i++].copy);
	}
	free(stock);
}

static void	as(struct s_stock_str *s, int size, char *str, char *copy)
{
	s->size = size;
	s->str = str;
	s->copy = copy;
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*stk;
	struct s_stock_str	*buf;
	int					i;

	stk = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!stk)
		return (NULL);
	buf = stk;
	i = 0;
	while (i < ac)
	{
		as(buf, ft_strlen(av[i]), av[i], ft_strdup(av[i]));
		if (!buf->copy)
		{
			ft_free_stock(stk, i);
			return (NULL);
		}
		buf++;
		i++;
	}
	as(buf, 0, 0, 0);
	return (stk);
}
