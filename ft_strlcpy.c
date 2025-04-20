/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:32:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/17 19:15:37 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	char src[] = "Hello World";
	char dest[50];
	size_t r1 = ft_strlcpy(dest, src, 12);
	
	printf("ft_strlcpy len: %ld\n", r1);
	printf("dest: %s\n", dest);

	char d2[50] = "Hello World";
	size_t r2 = strlcpy(d2, src, 12);
	
	printf("strlcpy len: %ld\n", r2);
	printf("dest: %s\n", d2);

	return (0);
} */