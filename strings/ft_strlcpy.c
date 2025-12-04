/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:32:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 13:16:57 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;

	if (size == 0)
		return (ft_strlen(src));
	idx = 0;
	while (src[idx] != '\0' && (idx < size - 1))
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (ft_strlen(src));
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char b[10];
	size_t numb;
	
	numb = ft_strlcpy(b, "ABC", 3);
	printf("len: %zu + 1\n", numb);
	printf("ft_strlcpy: %s\n", b);
	printf("strlcpy: %s\n\n", b);

	
	numb = ft_strlcpy(b, "hello", 6);
	printf("len: %zu + 1\n", numb);
	printf("ft_strlcpy: %s\n", b);
	printf("strlcpy: %s\n\n", b);
	
	
	numb = ft_strlcpy(b, "hello", 3);
	printf("len: %zu + 1\n", numb);
	printf("ft_strlcpy: %s\n", b);
	printf("strlcpy: %s\n\n", b);

	
	numb = ft_strlcpy(b, "ABC", 1);
	printf("len: %zu + 1\n", numb);
	printf("ft_strlcpy: %s\n", b);
	printf("strlcpy: %s\n\n", b);

	
	numb = ft_strlcpy(b, "AB", 3);
	printf("len: %zu + 1\n", numb);
	printf("ft_strlcpy: %s\n", b);
	printf("strlcpy: %s\n", b);

	return (0);
} */