/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:52:20 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/11/03 22:24:34 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			idx;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		tmp_dst[idx] = tmp_src[idx];
		idx++;
	}
	return (dest);
}

/* int main()
{
	char *b[10];
    printf("ft_memcpy: %s\n", (char *)ft_memcpy(b, "ABC\0", 3));
    printf("memcpy: %s\n\n", (char *)memcpy(b, "ABC\0", 3));

	printf("ft_memcpy: %s\n", (char *)ft_memcpy(b, "hello", 5));
	printf("memcpy: %s\n\n", (char *)memcpy(b, "hello", 5));

	printf("ft_memcpy: %s\n", (char *)ft_memcpy(b, "ABC\0", 1));
	printf("memcpy: %s\n\n", (char *)memcpy(b, "ABC\0", 1));

	printf("ft_memcpy: %s\n", (char *)ft_memcpy(b, "AB\0", 0));
	printf("memcpy: %s\n\n", (char *)memcpy(b, "AB\0", 0));

	printf("ft_memcpy: %s\n", (char *)ft_memcpy(b, "ABK\0", 2));
	printf("memcpy: %s\n\n", (char *)memcpy(b, "ABK\0", 2));

	printf("ft_memcpy: %s\n", (char *)ft_memcpy(b, "ABp55", 5));
	printf("memcpy: %s\n", (char *)memcpy(b, "ABp55", 5));

	// printf("\t%s\n", (char *)memcpy(b, NULL, 3)); //segfault
	// printf("\t%s\n", (char *)memcpy(NULL, "ABC", 3)); //segfault
	// printf("\t%s\n", (char *)memcpy(NULL, NULL, 3)); //segfault
    
    return (0);
} */