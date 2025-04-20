/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:30:46 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 16:37:09 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	idx;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len + size);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (src_len + size);
	idx = 0;
	while ((dest_len + idx) < (size - 1) && (src[idx] != '\0'))
	{
		dest[dest_len + idx] = src[idx];
		idx++;
	}
	dest[dest_len + idx] = '\0';
	return (dest_len + src_len);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[] = "World";
	char dest[50] = "Hello ";
	size_t r1 = ft_strlcat(dest, src, 12);
	
	printf("ft_strlcat len: %ld\n", r1);
	printf("dest: %s\n", dest);

	char d2[50] = "Hello ";
	size_t r2 = strlcat(d2, src, 12);
	
	printf("strlcat len: %ld\n", r2);
	printf("dest: %s\n", d2);

	return (0);
} */