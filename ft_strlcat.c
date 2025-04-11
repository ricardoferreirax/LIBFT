/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:30:46 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/10 14:38:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	while (src[i] != '\0' && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/* #include <stdio.h>

int	main(void)
{
	char a[] = "Hello";  // src
	char b[50] = " World";
	printf("BEFORE: src: %s and dest: %s\n", a, b);
	ft_strlcat(b, a, 11);
	printf("AFTER: src: %s and dest: %s\n", a, b);

	return (0);
} */