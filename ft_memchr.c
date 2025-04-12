/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:41:47 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/12 13:39:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			idx;

	str = (unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		if (str[idx] == (unsigned char)c)
			return ((void *)(str + idx));
		idx++;
	}
	return (NULL);
}


/* int main()
{
	char str_memchr[10]= "Hello";
	
	printf("ft_memchr: %p\n", ft_memchr(str_memchr, 'e', 2));
	printf("memchr: %p\n", memchr(str_memchr, 'e', 2));
} */
