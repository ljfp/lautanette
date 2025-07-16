/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:48:40 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/16 21:38:42 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int main(void)
{
    // Define test cases
    struct TestCase {
        char *haystack;
        char *needle;
        char *description;
    };

    struct TestCase tests[] = {
        {"Hello, world!", "world", "Basic search"},
        {"Hello, world!", "Hello", "Match at beginning"},
        {"Hello, world!", "world!", "Match at end"},
        {"Hello, world!", "lo, wo", "Match in middle"},
        {"Hello, world!", "", "Empty needle"},
        {"Hello, world!", "planet", "No match"},
        {"", "test", "Empty haystack"},
        {"banana", "ana", "Multiple potential matches"},
        {"abababa", "ababa", "Overlapping pattern"},
        {"Hello, world!", "WORLD", "Case sensitivity check"},
        {"aaaaaa", "aaa", "Repeated characters"}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;
    
    printf("Testing ft_strstr implementation:\n");
    printf("=================================\n\n");

    for (int i = 0; i < num_tests; i++)
    {
        char *haystack = tests[i].haystack;
        char *needle = tests[i].needle;
        char *description = tests[i].description;
        
        // Run both implementations
        char *ft_result = ft_strstr(haystack, needle);
        char *std_result = strstr(haystack, needle);
        
        // Compare results
        int is_correct = 1;
        if (ft_result == 0 && std_result == 0)
            is_correct = 1;
        else if (ft_result == 0 || std_result == 0)
            is_correct = 0;
        else
            is_correct = (ft_result - haystack) == (std_result - haystack);
        
        // Display result
        printf("Test %d: %s\n", i + 1, description);
        printf("  Haystack: \"%s\"\n", haystack);
        printf("  Needle:   \"%s\"\n", needle);
        
        if (ft_result)
            printf("  ft_strstr found: \"%s\" at position %ld\n", 
                   ft_result, ft_result - haystack);
        else
            printf("  ft_strstr found: 0\n");
            
        if (std_result)
            printf("  strstr found:    \"%s\" at position %ld\n", 
                   std_result, std_result - haystack);
        else
            printf("  strstr found:    0\n");
        
        if (is_correct)
        {
            printf("  ✅ PASS\n");
            passed++;
        }
        else
            printf("  ❌ FAIL\n");
            
        printf("\n");
    }
    
    printf("Summary: %d/%d tests passed\n", passed, num_tests);
    
    return 0;
}
