/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:58:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/10 11:08:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int num)
{
	int			len;
	long int	n;

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
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*res;
	long int	num;

	num = n;
	size = count_digits(n);
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
	res[size--] = '\0';
	while (size >= 0 && num > 0)
	{
		res[size] = (num % 10) + '0';
		size--;
		num = num / 10;
	}
	return (res);
}

/* #include <stdio.h>

int main()
{
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa (2147483647));

	return (0);
} */