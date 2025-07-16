/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:28:45 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/14 14:46:17 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ptr;
	unsigned int	i;

	ptr = dest;
	while (*dest)
	{
		dest++;
	}
	i = 0;
	while (*src && i < nb)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (ptr);
}

int main(void)
{
    // Test 1: Normal case with limit less than source length
    char test1_dest[50] = "Hello, ";
    char test1_src[] = "World!";
    printf("Test 1 (Normal case with limit):\n");
    printf("Before: dest = \"%s\", src = \"%s\", n = 3\n", test1_dest, test1_src);
    ft_strncat(test1_dest, test1_src, 3);
    printf("After: dest = \"%s\"\n", test1_dest);
    printf("Expected: \"Hello, Wor\"\n\n");

    // Test 2: n = 0 (should not concatenate anything)
    char test2_dest[50] = "Hello!";
    char test2_src[] = "World";
    printf("Test 2 (n = 0):\n");
    printf("Before: dest = \"%s\", src = \"%s\", n = 0\n", test2_dest, test2_src);
    ft_strncat(test2_dest, test2_src, 0);
    printf("After: dest = \"%s\"\n", test2_dest);
    printf("Expected: \"Hello!\"\n\n");

    // Test 3: n greater than source length
    char test3_dest[50] = "Hello, ";
    char test3_src[] = "World!";
    printf("Test 3 (n > source length):\n");
    printf("Before: dest = \"%s\", src = \"%s\", n = 10\n", test3_dest, test3_src);
    ft_strncat(test3_dest, test3_src, 10);
    printf("After: dest = \"%s\"\n", test3_dest);
    printf("Expected: \"Hello, World!\"\n\n");

    // Test 4: Empty source string
    char test4_dest[50] = "Hello!";
    char test4_src[] = "";
    printf("Test 4 (Empty source):\n");
    printf("Before: dest = \"%s\", src = \"%s\", n = 5\n", test4_dest, test4_src);
    ft_strncat(test4_dest, test4_src, 5);
    printf("After: dest = \"%s\"\n", test4_dest);
    printf("Expected: \"Hello!\"\n\n");

    // Test 5: Multiple concatenations
    char test5_dest[50] = "Hello";
    printf("Test 5 (Multiple concatenations):\n");
    printf("Initial: dest = \"%s\"\n", test5_dest);
    ft_strncat(test5_dest, " ", 1);
    printf("After 1st concat (n=1): dest = \"%s\"\n", test5_dest);
    ft_strncat(test5_dest, "World", 3);
    printf("After 2nd concat (n=3): dest = \"%s\"\n", test5_dest);
    ft_strncat(test5_dest, "!!!!", 2);
    printf("After 3rd concat (n=2): dest = \"%s\"\n", test5_dest);
    printf("Expected: \"Hello Wor!!\"\n\n");

    // Test 6: Comparison with standard strncat
    char test6_ft_dest[50] = "Testing ";
    char test6_std_dest[50] = "Testing ";
    char test6_src[] = "function implementation";
    unsigned int n = 8;
    
    printf("Test 6 (Comparison with standard strncat):\n");
    printf("Before: ft_dest = \"%s\", std_dest = \"%s\", src = \"%s\", n = %u\n", 
           test6_ft_dest, test6_std_dest, test6_src, n);
    
    ft_strncat(test6_ft_dest, test6_src, n);
    strncat(test6_std_dest, test6_src, n);
    
    printf("After ft_strncat: \"%s\"\n", test6_ft_dest);
    printf("After standard strncat: \"%s\"\n", test6_std_dest);
    
    if (strcmp(test6_ft_dest, test6_std_dest) == 0)
        printf("Result: ✅ MATCH\n\n");
    else
        printf("Result: ❌ MISMATCH\n\n");

    return 0;
}
