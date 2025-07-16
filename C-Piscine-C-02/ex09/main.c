/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:14:15 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/16 21:35:03 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

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
