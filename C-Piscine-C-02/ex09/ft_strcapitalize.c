/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:14:15 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/14 12:12:07 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);
void	low_to_upper(char *str);
void	upper_to_low(char *str);
int		is_alphanumeric(char c);

void	low_to_upper(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		*str -= 32;
	}
}

void	upper_to_low(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
	{
		*str += 32;
	}
}

int	is_alphanumeric(char c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int	check_prev(char *str)
{
	char	prev;

	prev = *(str - 1);
	if (!(is_alphanumeric(prev)))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*ptr;

	ptr = str;
	low_to_upper(str);
	str++;
	while (*str)
	{
		if (check_prev(str) != 0)
			low_to_upper(str);
		else
			upper_to_low(str);
		str++;
	}
	return (ptr);
}

int	main(void)
{
	char test1[] = "hello world";
	char test2[] = "42words forty-two; fifty+one";
	char test3[] = "ALREADY CAPITALIZED";
	char test4[] = "miXeD CaSe StRiNg";
	char test5[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char test6[] = "aaaaTTTTttttTTTtttB42";
	
	printf("Test 1 before: \"%s\"\n", test1);
	printf("Test 1 after:  \"%s\"\n\n", ft_strcapitalize(test1));
	
	printf("Test 2 before: \"%s\"\n", test2);
	printf("Test 2 after:  \"%s\"\n\n", ft_strcapitalize(test2));
	
	printf("Test 3 before: \"%s\"\n", test3);
	printf("Test 3 after:  \"%s\"\n\n", ft_strcapitalize(test3));
	
	printf("Test 4 before: \"%s\"\n", test4);
	printf("Test 4 after:  \"%s\"\n\n", ft_strcapitalize(test4));
	
	printf("Test 5 before: \"%s\"\n", test5);
	printf("Test 5 after:  \"%s\"\n\n", ft_strcapitalize(test5));

	printf("Test 6 before: \"%s\"\n", test6);
	printf("Test 6 after: \"%s\"\n\n", ft_strcapitalize(test6));
	
	return (0);
}
