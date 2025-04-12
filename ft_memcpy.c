/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:52:20 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/12 13:34:19 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			idx;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
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
    char str1[] = "Hello, world";
    char str2[10];
    char *mine = ft_memcpy(str2, str1, 5);
    char *orig = memcpy(str2, str1, 5);
    printf("ft_memcpy: %s\n", mine);
    printf("memcpy: %s\n", orig);
    
    return (0);
} */