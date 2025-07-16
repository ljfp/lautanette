/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:22:37 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/16 21:30:51 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
    // Test case 1: Empty string (should return 1)
    printf("Test with empty string: %d\n", ft_str_is_printable(""));
    
    // Test case 2: Normal printable string (should return 1)
    printf("Test with printable string: %d\n", ft_str_is_printable("Hello, World!"));
    
    // Test case 3: String with various printable characters (should return 1)
    printf("Test with various printable chars: %d\n", ft_str_is_printable(" !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"));
    
    // Test case 4: String with control character (should return 0)
    printf("Test with newline character: %d\n", ft_str_is_printable("Hello\nWorld"));
    
    // Test case 5: String with tab character (should return 0)
    printf("Test with tab character: %d\n", ft_str_is_printable("Hello\tWorld"));
    
    // Test case 6: String with ASCII 0-31 characters (should return 0)
    char ctrl_char[2];
    ctrl_char[1] = '\0';
    printf("Testing control characters (ASCII 0-31):\n");
    for (int i = 0; i < 32; i++) {
        ctrl_char[0] = (char)i;
        printf("  ASCII %d: %d\n", i, ft_str_is_printable(ctrl_char));
    }
    
    // Test case 7: String with DEL character (ASCII 127) (should return 1)
    char del_char[2] = {127, '\0'};
    printf("Test with DEL character (127): %d\n", ft_str_is_printable(del_char));
    
    // Test case 8: String with character above DEL (should return 0)
    char extended_char[2] = {(char)128, '\0'};
    printf("Test with extended character (128): %d\n", ft_str_is_printable(extended_char));
    
    // Test case 9: String with all printable ASCII range (should return 1)
    char all_printable[96 + 1]; // Space (32) to DEL (127) + null terminator
    for (int i = 0; i < 96; i++)
        all_printable[i] = (char)(32 + i);
    all_printable[96] = '\0';
    printf("Test with all printable range (32-127): %d\n", ft_str_is_printable(all_printable));
    
    // Test case 10: Mixed printable and non-printable (should return 0)
    char mixed[4] = {'A', '\n', 'B', '\0'};
    printf("Test with mixed characters: %d\n", ft_str_is_printable(mixed));
    
    return 0;
}
