/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:41:47 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/21 10:05:08 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	size_t			idx;

	tmp_s = (unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		if (tmp_s[idx] == (unsigned char)c)
			return ((void *)(tmp_s + idx));
		idx++;
	}
	return (NULL);
}

/* int	main(void)
{
	const char s[] = "Hello, World!";;

	printf("ft_memchr: %s\n", (char *)ft_memchr(s, 'e', 5));
	printf("memchr: %s\n\n", (char *)memchr(s, 'e', 5));

	printf("ft_memchr: %s\n", (char *)ft_memchr(s, 'o', 10));
	printf("memchr: %s\n\n", (char *)memchr(s, 'o', 10));

	printf("ft_memchr: %s\n", (char *)ft_memchr(s, 'l', 3));
	printf("memchr: %s\n\n", (char *)memchr(s, 'l', 3));

	printf("ft_memchr: %s\n", (char *)ft_memchr(s, 101, 2));
	printf("memchr: %s\n", (char *)memchr(s, 101, 2));

	// printf("\t%p\n", ft_memchr(NULL, 'a', 1)); //segfault
	// printf("\t%p\n", ft_memchr(NULL, 'a', 1)); //segfault

	return (0);
} */
