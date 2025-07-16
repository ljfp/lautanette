/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:18:09 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/13 21:22:21 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address_in_hex(void *addr);
void	print_single_byte_in_hex(unsigned char a_byte);
void	print_string_in_hex(char *str, unsigned int size);
void	print_printable_chars(void *str, unsigned int size);
void	*ft_print_memory(void *addr, unsigned int size);

void	print_address_in_hex(void *addr)
{
	unsigned char	*ptr_to_addr;
	int				i;

	ptr_to_addr = (unsigned char *) &addr;
	i = 7;
	while (i >= 0)
	{
		print_single_byte_in_hex(*(ptr_to_addr + i));
		i--;
	}
	write(1, ":", 1);
}

void	print_single_byte_in_hex(unsigned char a_byte)
{
	char	c;

	if ((a_byte / 16) < 10)
	{
		c = 48 + (a_byte / 16);
		write(1, &c, 1);
	}
	else
	{
		c = 87 + (a_byte / 16);
		write(1, &c, 1);
	}
	if ((a_byte % 16) < 10)
	{
		c = 48 + (a_byte % 16);
		write(1, &c, 1);
	}
	else
	{
		c = 87 + (a_byte % 16);
		write(1, &c, 1);
	}
}

void	print_string_in_hex(char *str, unsigned int size)
{
	int		i;
	int		limit;
	int		bytes_to_print;

	bytes_to_print = 16;
	if (size < 16)
		bytes_to_print = size;
	limit = bytes_to_print;
	i = 0;
	while (i < limit)
	{
		if (!(i % 2))
			write(1, " ", 1);
		print_single_byte_in_hex(*(unsigned char *)(str + i));
		i++;
	}
	while (i < 16)
	{
		if (!(i % 2))
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
	write(1, " ", 1);
}

void	print_printable_chars(void *str, unsigned int size)
{
	int		i;
	int		limit;

	limit = 16;
	if (size < 16)
		limit = size;
	i = 0;
	while (i < limit)
	{
		if (*(char *)(str + i) >= 32 && *(char *)(str + i) < 127)
			write(1, (char *)str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	if (size == 0)
		return (addr);
	while (size > 16)
	{
		print_address_in_hex(addr);
		print_string_in_hex(addr, size);
		print_printable_chars(addr, size);
		addr += 16;
		size -= 16;
	}
	print_address_in_hex(addr);
	print_string_in_hex(addr, size);
	print_printable_chars(addr, size);
	return (addr);
}

int 	main()
{
	/*
	char	empty[] = "";	
	char	str[] = "Bonjour les amin----";
	char	str1[] = "ches\t\n\tc  est fo----";
	char	str2[] = "u\ttout\tce qu on ----";
	char	str3[] = "peut faire avec\t----";
	char	str4[] = "\n\tprint_memory\n\n----";
	char 	str5[] = "\n\tlol.lol\n \0";
	*/
	char	fullstr[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";

	ft_print_memory((void *)fullstr, sizeof(fullstr));
	return (0);
}
