/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:48:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/12 20:12:18 by rmedeiro         ###   ########.fr       */
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
    char str1[] = "Hello, world";
    char str2[] = "Helli, world";
    int mine = ft_memcmp(str1, str2, 10);
	int orig = memcmp(str1, str2, 10);
    printf("ft_memcmp: %d\n", mine);
	printf("memcmp: %d\n", orig);
	return (0);
} */