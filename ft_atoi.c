/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:17:35 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 17:17:45 by rmedeiro         ###   ########.fr       */
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
	printf("ft_atoi: %d\n", ft_atoi("   \t\r\n\v\f-+123f"));
	printf("atoi: %d\n\n", atoi("   \t\r\n\v\f-+123f"));

	printf("ft_atoi: %d\n", ft_atoi("   \t\r\n\v\f-12 3f"));
	printf("atoi: %d\n\n", atoi("   \t\r\n\v\f-12 3f"));
	
	printf("ft_atoi: %d\n", ft_atoi("   \t\r\n\v\f -2147483648"));
	printf("atoi: %d\n\n", atoi("   \t\r\n\v\f -2147483648"));
	
	printf("ft_atoi: %d\n", ft_atoi("   \t\r\n\v\f 2147483647"));
	printf("atoi: %d\n\n", atoi("   \t\r\n\v\f 2147483647"));
	
	printf("ft_atoi: %d\n", ft_atoi(""));
	printf("atoi: %d\n", atoi(""));
	
	// printf("\t%d\n", ft_atoi(NULL)); //segfault
	// printf("\t%d\n", atoi(NULL)); //segfault

    return (0);
} */