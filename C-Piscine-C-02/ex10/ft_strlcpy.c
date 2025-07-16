/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:09:27 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/13 00:43:03 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int				ft_strlen(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size -1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

int main(void)
{
    char source[] = "Hello, World!";
    char destination[20];
    unsigned int len;
    
    // Test ft_strlcpy with normal case
    len = ft_strlcpy(destination, source, sizeof(destination));
    printf("Testing ft_strlcpy (normal case):\n");
    printf("Source: \"%s\" (length: %u)\n", source, len);
    printf("Destination: \"%s\"\n\n", destination);
    
    // Test with exact size
    len = ft_strlcpy(destination, source, ft_strlen(source) + 1);
    printf("Testing ft_strlcpy (exact size):\n");
    printf("Source: \"%s\" (length: %u)\n", source, len);
    printf("Destination: \"%s\"\n\n", destination);
    
    // Test with truncation
    len = ft_strlcpy(destination, source, 7);
    printf("Testing ft_strlcpy (truncation):\n");
    printf("Source: \"%s\" (length: %u)\n", source, len);
    printf("Destination: \"%s\"\n\n", destination);
    
    // Test with size 0
    len = ft_strlcpy(destination, source, 0);
    printf("Testing ft_strlcpy (size 0):\n");
    printf("Source: \"%s\" (length: %u)\n", source, len);
    printf("Destination: \"%s\" (should not be modified)\n\n", destination);
    
    // Test with empty source
    len = ft_strlcpy(destination, "", 5);
    printf("Testing ft_strlcpy (empty source):\n");
    printf("Source: \"\" (length: %u)\n", len);
    printf("Destination: \"%s\"\n", destination);
    
    return (0);
}
