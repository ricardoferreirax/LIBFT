/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:30:46 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 13:16:51 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

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
	char b[50] = "Hello";

	printf("len: %zu + 1\n", ft_strlcat(b, " Wonderful", 16));
	printf("ft_strlcat: %s\n", b);
	printf("strlcat: %s\n\n", b);

	printf("len: %zu + 1\n", ft_strlcat(b, " World!", 23));
	printf("ft_strlcat: %s\n", b);
	printf("strlcat: %s\n", b);

	return (0);
} */