/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:48:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 17:59:11 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				idx;
	unsigned char		*tmp_s1;
	unsigned char		*tmp_s2;

	if (n == 0)
		return (0);
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	idx = 0;
	while (tmp_s1[idx] == tmp_s2[idx] && idx < n - 1)
		idx++;
	return (tmp_s1[idx] - tmp_s2[idx]);
}

/* int main()
{
    printf("ft_memcmp: %d\n", ft_memcmp("ABC", "ABC", 3));
    printf("memcmp: %d\n\n", ft_memcmp("ABC", "ABC", 3));
	
	printf("ft_memcmp: %d\n", ft_memcmp("ABC", "AC", 2));
	printf("memcmp: %d\n\n", ft_memcmp("ABC", "AC", 2));

	printf("ft_memcmp: %d\n", ft_memcmp("BC", "ABC", 0));
	printf("memcmp: %d\n\n", ft_memcmp("BC", "ABC", 0));

	printf("ft_memcmp: %d\n", ft_memcmp("ABC", "AB", 3));
	printf("memcmp: %d\n\n", ft_memcmp("ABC", "AB", 3));
	
	printf("ft_memcmp: %d\n", ft_memcmp("AB", "ABC", 3));
	printf("memcmp: %d\n", ft_memcmp("AB", "ABC", 3));

	// printf("ft_memcmp: %d\n", ft_memcmp("ABC", NULL, 3)); //segfault
	// printf("ft_memcmp: %d\n", ft_memcmp(NULL, "ABC", 3)); //segfault
	// printf("ft_memcmp: %d\n", ft_memcmp(NULL, NULL, 3)); //segfault
	
	return (0);
} */