/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:12:17 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/12 13:26:21 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*buffer;

	idx = 0;
	buffer = (unsigned char *)s;
	while (idx < n)
		buffer[idx++] = (unsigned char)c;
	return (s);
}

/* int main() 
{
    char str[] = "Hello World!";
	char *mine = ft_memset(str, 'X', 5);
	char *orig = memset(str, 'X', 5);
    printf("After ft_memset: %s\n", mine); 
    printf("After memset: %s\n", orig);
    return (0);
} */