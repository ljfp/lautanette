/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:55:02 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/14 13:04:42 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*s1 && (*s1 == *s2) && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

int main(void)
{
    // Test cases
    char *test_pairs[][2] = {
        {"hello", "hello"},         // Identical strings
        {"hello", "helicopter"},    // Same prefix
        {"apple", "banana"},        // Different strings
        {"apple", "apple123"},      // Same prefix
        {"", "hello"},              // Empty s1
        {"hello", ""},              // Empty s2
        {"", ""},                   // Both empty
        {"abc", "abd"},             // Differ by one character
        {"hello world", "hello"},   // s1 longer than s2
        {"hello", "hello world"}    // s2 longer than s1
    };
    
    unsigned int n_values[] = {0, 1, 3, 5, 10};
    int num_tests = sizeof(test_pairs) / sizeof(test_pairs[0]);
    int num_n_values = sizeof(n_values) / sizeof(n_values[0]);
    
    for (int i = 0; i < num_tests; i++)
    {
        char *s1 = test_pairs[i][0];
        char *s2 = test_pairs[i][1];
        
        for (int j = 0; j < num_n_values; j++)
        {
            unsigned int n = n_values[j];
            
            int result = ft_strncmp(s1, s2, n);
            int expected = strncmp(s1, s2, n);
            
            printf("Test: \"%s\" vs \"%s\" with n=%u\n", s1, s2, n);
            printf("  ft_strncmp result: %d\n", result);
            printf("  strncmp result:    %d\n", expected);
            
            if ((result < 0 && expected < 0) || 
                (result > 0 && expected > 0) || 
                (result == 0 && expected == 0))
                printf("  ✅ PASS (signs match)\n\n");
            else
                printf("  ❌ FAIL (signs don't match)\n\n");
        }
    }
    
    return 0;
}
