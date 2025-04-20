/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:24:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/17 12:10:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			idx;
	unsigned char	*tmp_s;

	idx = 0;
	tmp_s = (unsigned char *)s;
	while (idx < n)
		tmp_s[idx++] = 0;
}

/* #include <stdio.h>

int	main(void)
{
	char str[10] = "Hello";
	ft_bzero(str + 3, 5);
	printf("After ft_bzero: '%s'\n", str);

	return (0);
} */