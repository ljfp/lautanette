/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:31:28 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/12 17:11:48 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_start = dest;
	while (*dest != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return dest_start;
}

int main(int argc, char *argv[])
{
    char source[100];
    char destination[100];
    
    strcpy(destination, "AAAAAAAAAA");
    
    if (argc > 2) {
        printf("Original dest: %s\n", destination);
        printf("Source string: %s\n", argv[1]);
        char *result = ft_strcpy(destination, argv[1]);
        printf("Copied string: %s\n", destination);
        printf("Return value points to: %s\n", result);
    } else {
        strcpy(source, "Hello, world!");
        printf("Original dest: %s\n", destination);
        printf("Source string: %s\n", source);
        char *result = ft_strcpy(destination, source);
        printf("Copied string: %s\n", destination);
        printf("Return value points to: %s\n", result);
    }	
}
