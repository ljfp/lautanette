/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:30:17 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/16 21:39:04 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
    printf("===== ft_strlcat Testing =====\n\n");
    
    // Test 1: Normal concatenation with sufficient buffer
    char test1_dest[20] = "Hello, ";
    char test1_src[] = "World!";
    unsigned int test1_size = sizeof(test1_dest);
    unsigned int test1_result = ft_strlcat(test1_dest, test1_src, test1_size);
    
    printf("Test 1: Normal concatenation with sufficient buffer\n");
    printf("  dest before: \"Hello, \"\n");
    printf("  src: \"%s\"\n", test1_src);
    printf("  size: %u\n", test1_size);
    printf("  Result: \"%s\"\n", test1_dest);
    printf("  Return value: %u\n", test1_result);
    printf("  Expected return: %u (length of \"Hello, World!\")\n\n", ft_strlen("Hello, ") + ft_strlen("World!"));
    
    // Test 2: Buffer exactly fits concatenated string
    char test2_dest[13] = "Hello, ";
    char test2_src[] = "World!";
    unsigned int test2_size = sizeof(test2_dest);
    unsigned int test2_result = ft_strlcat(test2_dest, test2_src, test2_size);
    
    printf("Test 2: Buffer exactly fits concatenated string\n");
    printf("  dest before: \"Hello, \"\n");
    printf("  src: \"%s\"\n", test2_src);
    printf("  size: %u\n", test2_size);
    printf("  Result: \"%s\"\n", test2_dest);
    printf("  Return value: %u\n", test2_result);
    printf("  Expected return: %u\n\n", ft_strlen("Hello, ") + ft_strlen("World!"));
    
    // Test 3: Buffer too small (truncation expected)
    char test3_dest[10] = "Hello, ";
    char test3_src[] = "World!";
    unsigned int test3_size = sizeof(test3_dest);
    unsigned int test3_result = ft_strlcat(test3_dest, test3_src, test3_size);
    
    printf("Test 3: Buffer too small (truncation expected)\n");
    printf("  dest before: \"Hello, \"\n");
    printf("  src: \"%s\"\n", test3_src);
    printf("  size: %u\n", test3_size);
    printf("  Result: \"%s\"\n", test3_dest);
    printf("  Return value: %u\n", test3_result);
    printf("  Expected return: %u\n\n", ft_strlen("Hello, ") + ft_strlen("World!"));
    
    // Test 4: Empty source string
    char test4_dest[20] = "Hello!";
    char test4_src[] = "";
    unsigned int test4_size = sizeof(test4_dest);
    unsigned int test4_result = ft_strlcat(test4_dest, test4_src, test4_size);
    
    printf("Test 4: Empty source string\n");
    printf("  dest before: \"Hello!\"\n");
    printf("  src: \"%s\"\n", test4_src);
    printf("  size: %u\n", test4_size);
    printf("  Result: \"%s\"\n", test4_dest);
    printf("  Return value: %u\n", test4_result);
    printf("  Expected return: %u\n\n", ft_strlen("Hello!") + ft_strlen(""));
    
    // Test 5: Empty destination string
    char test5_dest[20] = "";
    char test5_src[] = "Hello!";
    unsigned int test5_size = sizeof(test5_dest);
    unsigned int test5_result = ft_strlcat(test5_dest, test5_src, test5_size);
    
    printf("Test 5: Empty destination string\n");
    printf("  dest before: \"%s\"\n", test5_dest);
    printf("  src: \"%s\"\n", test5_src);
    printf("  size: %u\n", test5_size);
    printf("  Result: \"%s\"\n", test5_dest);
    printf("  Return value: %u\n", test5_result);
    printf("  Expected return: %u\n\n", ft_strlen("") + ft_strlen("Hello!"));
    
    // Test 6: Size = 0
    char test6_dest[20] = "Hello!";
    char test6_src[] = "World!";
    unsigned int test6_size = 0;
    unsigned int test6_result = ft_strlcat(test6_dest, test6_src, test6_size);
    
    printf("Test 6: Size = 0\n");
    printf("  dest before: \"Hello!\"\n");
    printf("  src: \"%s\"\n", test6_src);
    printf("  size: %u\n", test6_size);
    printf("  Result: \"%s\"\n", test6_dest); // This should still be "Hello!"
    printf("  Return value: %u\n", test6_result);
    printf("  Expected return: %u\n\n", ft_strlen("World!") + 0);
    
    return 0;
}
