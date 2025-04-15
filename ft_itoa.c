/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:58:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/13 12:08:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(long int nb)
{
	int			len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	num;
	int			size;
	char		*res;

	num = n;
	size = numlen(n);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	res[size] = '\0';
	while (size > 0 && num > 0)
	{
		res[--size] = (num % 10) + '0';
		num = num / 10;
	}
	return (res);
}

/* #include <stdio.h>

int main (void)
{
	int	n;

	n = 234;
	printf("lenght of the number: %i\n", numlen(n));
	printf("original number: %i\n", n);
	printf("char number: %s\n", ft_itoa(n));
} */