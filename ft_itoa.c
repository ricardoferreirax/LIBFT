/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:58:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 21:02:21 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numberlen(int num)
{
	int			len;
	long		n;

	n = num;
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*number;
	long		nbr;

	nbr = n;
	len = numberlen(nbr);
	number = malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	if (nbr == 0)
		number[0] = '0';
	if (nbr < 0)
	{
		number[0] = '-';
		nbr = -nbr;
	}
	number[len--] = '\0';
	while (len >= 0 && nbr > 0)
	{
		number[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (number);
}

/* #include <stdio.h>

int main (void)
{
	printf("%s\n", ft_itoa(-123456));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(10));
	printf("%s\n", ft_itoa(0));
	
	return (0);
} */