/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:12:17 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 18:33:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*tmp_s;

	idx = 0;
	tmp_s = (unsigned char *)s;
	while (idx < n)
		tmp_s[idx++] = (unsigned char)c;
	return (s);
}

/* int main() 
{
	char a[] = "Hello, World!";
	
    printf("ft_memset: %s\n", (char *)ft_memset(a, 'e', 1));
    printf("memset: %s\n\n", (char *)memset(a, 'e', 1));
	
	printf("ft_memset: %s\n", (char *)ft_memset(a, 'o', 10));
	printf("memset: %s\n\n", (char *)memset(a, 'o', 10));
	
	printf("ft_memset: %s\n", (char *)ft_memset(a, ' ', 4));
	printf("memset: %s\n", (char *)memset(a, ' ', 4));

	// printf("\t%s\n", (char *)ft_memset(a, 'a', 500));
	// printf("\t%s\n", (char *)ft_memset(NULL, 'a', 1));
    return (0);
} */