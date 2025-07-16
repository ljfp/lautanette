/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:48:29 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/16 21:37:56 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int main(void)
{
    // Test cases
    char *test_pairs[][2] = {
        {"hello", "hello"},         // Identical strings
        {"hello", "hello world"},   // s2 longer than s1
        {"hello world", "hello"},   // s1 longer than s2
        {"apple", "banana"},        // Different strings
        {"apple", "apple123"},      // Same prefix
        {"", "hello"},              // Empty s1
        {"hello", ""},              // Empty s2
        {"", ""},                   // Both empty
        {"abc", "abd"},             // Differ by one character
        {"z", "a"},                 // Test character comparison
		{"ABC", "ABC"},
		{"ABC", "AB"},
		{"ABA", "ABZ"},
		{"ABJ", "ABC"}
    };
    
    int num_tests = sizeof(test_pairs) / sizeof(test_pairs[0]);
    
    for (int i = 0; i < num_tests; i++)
    {
        char *s1 = test_pairs[i][0];
        char *s2 = test_pairs[i][1];
        
        int result = ft_strcmp(s1, s2);
        int expected = strcmp(s1, s2);
        
        printf("Test %d: \"%s\" vs \"%s\"\n", i + 1, s1, s2);
        printf("  ft_strcmp result: %d\n", result);
        printf("  strcmp result:    %d\n", expected);
        
        if ((result < 0 && expected < 0) || 
            (result > 0 && expected > 0) || 
            (result == 0 && expected == 0))
            printf("  ✅ PASS (signs match)\n\n");
        else
            printf("  ❌ FAIL (signs don't match)\n\n");
    }
    
    return 0;
}
