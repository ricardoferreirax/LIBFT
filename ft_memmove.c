/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:02:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 18:26:28 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*tmp_src;
	unsigned char		*tmp_dst;
	size_t				idx;

	tmp_src = (const unsigned char *)src;
	tmp_dst = (unsigned char *)dest;
	if (tmp_dst > tmp_src)
	{
		while (n-- > 0)
			tmp_dst[n] = tmp_src[n];
	}
	else
	{
		idx = 0;
		while (idx < n)
		{
			tmp_dst[idx] = tmp_src[idx];
			idx++;
		}
	}
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char str1[] = "abcdef";
	char str2[] = "abcdef";
    
	ft_memmove(str1 + 2, str1, 4);
	printf("ft_memmove: %s\n", str1);
	ft_memmove(str2, str2 + 2, 4);
	printf("ft_memmove: %s\n", str2);
} */
