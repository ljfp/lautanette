/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:00:29 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/14 19:14:46 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int				ft_atoi(char *str);
unsigned int	is_space(unsigned char c);

unsigned int	is_space(unsigned char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	unsigned int	minus_signs;
	unsigned int	result;

	minus_signs = 0;
	result = 0;
	while (is_space((unsigned char) *str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus_signs++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (minus_signs % 2 == 1)
		result = -result;
	return (result);
}

int main(void)
{
    // Array of test cases
    char *test_cases[] = {
        "42",                   // Basic positive number
        "-42",                  // Basic negative number
        "0",                    // Zero
        "    42",               // Number with leading spaces
        "\t\n\r\f\v 42",        // Number with various whitespaces
        "+42",                  // Number with plus sign
        "++42",                 // Number with multiple plus signs
        "--42",                 // Number with multiple minus signs (should be positive)
        "---42",                // Three minus signs (should be negative)
        "+-+42",                // Mixed signs
        "-+42",                 // Minus then plus
        "   -42",               // Spaces and sign
        "   +42",               // Spaces and plus sign
        "   --+-+-+-+42",       // Complex sign pattern
        "42abc",                // Number followed by letters
        "   42abc",             // Spaces, number, letters
        "-42abc",               // Negative number followed by letters
        "   -42abc",            // Spaces, sign, number, letters
        "   --+-+-+-+42abc",    // Complex sign pattern with trailing chars
        "123456789",            // Large number
        "-123456789",           // Large negative number
        "2147483647",           // INT_MAX
        "-2147483648"           // INT_MIN
    };
    
    // Array of display strings (for better output formatting)
    char *display_strings[] = {
        "42",
        "-42",
        "0",
        "    42",
        "\\t\\n\\r\\f\\v 42",    // Escaped version for display
        "+42",
        "++42",
        "--42",
        "---42",
        "+-+42",
        "-+42",
        "   -42",
        "   +42",
        "   --+-+-+-+42",
        "42abc",
        "   42abc",
        "-42abc",
        "   -42abc",
        "   --+-+-+-+42abc",
        "123456789",
        "-123456789",
        "2147483647",
        "-2147483648"
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("%-25s | %-15s\n", "Test String", "ft_atoi Result");
    printf("------------------------------------------\n");
    
    for (int i = 0; i < num_tests; i++)
    {
        int result = ft_atoi(test_cases[i]);
        printf("%-25s | %-15d\n", display_strings[i], result);
    }
    
    // Additional example from the problem statement
    printf("\nSpecific example from problem statement:\n");
    char complex_example[] = "\n-1234\n---+--+1234ab567";
    printf("\"\\n-1234\\n---+--+1234ab567\" => %d\n", ft_atoi(complex_example));
    
    return (0);
}
