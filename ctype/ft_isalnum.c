/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:33:58 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:20:58 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctype.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/* #include <stdio.h>

int main()
{
	printf("'a': %d\n", ft_isalnum('a'));
	printf("'1': %d\n", ft_isalnum('1'));
	printf("'B': %d\n", ft_isalnum('B'));
	printf("'!': %d\n", ft_isalnum('!'));
	printf("'\n': %d\n", ft_isalnum('\n'));
	printf("140: %d\n", ft_isalnum(140));

	return (0);
} */