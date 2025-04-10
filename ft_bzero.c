/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:24:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/10 11:34:41 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*array;

	i = 0;
	array = (unsigned char *)s;
	while (i < n)
	{
		array[i] = 0;
		i++;
	}
}

/* #include <stdio.h>

int	main(void)
{
	char str[10] = "Hello";
	ft_bzero(str + 3, 4);
	printf("After ft_bzero: '%s'\n", str);

	return (0);
} */