/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:17:35 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/10 10:58:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/* #include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *test1 = " ---+--+1234ab567";
	char *test2 = "  42abc54";
	char *test3= "2147483647";
    char *test4= "-2147483648";

    printf("String: '%s', ft_atoi: %d\n", test1, ft_atoi(test1));
	printf("String: '%s', atoi: %d\n", test1, atoi(test1));
	
    printf("String: '%s', ft_atoi: %d\n", test2, ft_atoi(test2));
	printf("String: '%s', atoi: %d\n", test2, atoi(test2));
	
    printf("String: '%s', ft_atoi: %d\n", test3, ft_atoi(test3));
	printf("String: '%s', atoi: %d\n", test3, atoi(test3));
	
    printf("String: '%s', ft_atoi: %d\n", test4, ft_atoi(test4));
	printf("String: '%s', atoi: %d\n", test4, atoi(test4));

    return (0);
} */