/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:48:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/11 11:05:35 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*ptr1;
	unsigned char		*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
		{
			return (ptr1[i] - ptr2[i]);
		}
		i++;
	}
	return (0);
}

/* int main()
{
	char str_memcmp1[] = "Hello World";
	char str_memcmp2[] = "HelloWorld";

	int res_mine = ft_memcmp(str_memcmp1, str_memcmp2, 10);
	int res_orig = memcmp(str_memcmp1, str_memcmp2, 10);

	printf("ft_memcmp: %d\n", res_mine);
	printf("memcmp: %d\n", res_orig);

	return 0;
}  */
