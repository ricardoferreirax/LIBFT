/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:50:51 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 17:35:06 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* #include <stdio.h>

int main()
{
	printf("'a': %d\n", ft_isascii('a'));
	printf("'1': %d\n", ft_isascii('1'));
	printf("'B': %d\n", ft_isascii('B'));
	printf("'!': %d\n", ft_isascii('!'));
	printf("'\\n': %d\n", ft_isascii('\n'));
	printf("140: %d\n", ft_isascii(140));

	return (0);
} */
