/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:40:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/11/01 16:28:12 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/* int main()
{
	printf("'a': %d\n", ft_isalpha('a'));
	printf("'1': %d\n", ft_isalpha('1'));
	printf("'B': %d\n", ft_isalpha('B'));
	printf("'!': %d\n", ft_isalpha('!'));
	printf("'\\n': %d\n", ft_isalpha('\n'));
	printf("140: %d\n", ft_isalpha(140));

	return (0);
} */