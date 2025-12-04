/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:52:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:21:14 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctype.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* #include <stdio.h>

int main()
{
	printf("'a': %d\n", ft_isdigit('a'));
	printf("'1': %d\n", ft_isdigit('1'));
	printf("'B': %d\n", ft_isdigit('B'));
	printf("'!': %d\n", ft_isdigit('!'));
	printf("'\\n': %d\n", ft_isdigit('\n'));
	printf("58: %d\n", ft_isdigit(52));

	return (0);
} */