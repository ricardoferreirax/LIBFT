/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:54:33 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:21:24 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctype.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* #include <stdio.h>

int main()
{
	printf("'a': %d\n", ft_isprint('a'));
	printf("'1': %d\n", ft_isprint('1'));
	printf("'B': %d\n", ft_isprint('B'));
	printf("'!': %d\n", ft_isprint('!'));
	printf("'\\n': %d\n", ft_isprint('\n'));
	printf("140: %d\n", ft_isprint(140));

	return (0);
} */