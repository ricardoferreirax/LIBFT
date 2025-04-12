/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:02:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/12 13:03:06 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;
	size_t			idx;

	if (!dest && !src)
		return (NULL);
	tmp_src = (unsigned char *)src;
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
   char src[] = "Hello, World!";
   char dest[] = "Goodbye";
   
   printf("BEFORE: src: %s and dest: %s\n", src, dest);
   ft_memmove(dest, src, 5);
   printf("AFTER: src: %s and dest: %s\n", src, dest);
   ft_memmove(src, src + 7, 6);
   printf("AFTER: src: %s and dest: %s\n", src, dest);
   ft_memmove(src + 7, src, 6);
   printf("AFTER: src: %s and dest: %s\n", src, dest);

   return (0);
} */