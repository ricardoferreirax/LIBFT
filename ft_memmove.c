/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:02:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/10 18:13:27 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (p_dest < p_src && (p_dest || p_src))
	{
		i = 0;
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	else if (p_dest > p_src && (p_dest || p_src))
	{
		while (n > 0)
		{
			p_dest[n - 1] = p_src[n - 1];
			n--;
		}
	}
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
   char a[] = "ricardo";  // src
   char b[] = "abc"; // dest
   
   printf("BEFORE: src: %s and dest: %s\n",a, b);
   ft_memmove(b, a, 5);
   printf("AFTER: src: %s and dest: %s\n", a, b);

   return (0);
} */