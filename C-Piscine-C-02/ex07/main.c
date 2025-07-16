/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:50:52 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/16 21:34:33 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char	buffer1[] = "hola";
	char	buffer2[] = "HOLA";
	char	buffer3[] = "123ab123";
    char	buffer1_orig[50];
    char	buffer2_orig[50];
    char	buffer3_orig[50];
    
    strcpy(buffer1_orig, buffer1);
    strcpy(buffer2_orig, buffer2);
    strcpy(buffer3_orig, buffer3);
    
    printf("Before: %s After: %s\n", buffer1_orig, ft_strupcase(buffer1));
    printf("Before: %s After: %s\n", buffer2_orig, ft_strupcase(buffer2));
    printf("Before: %s After: %s\n", buffer3_orig, ft_strupcase(buffer3));
}
