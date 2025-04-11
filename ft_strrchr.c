/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:43:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/11 14:45:49 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	printf("ft_strrchr: %s\n", ft_strrchr("hujhk\0banana", '\0'));
	printf("strrchr: %s\n", strrchr("hujhk\0banana", '\0'));

	return (0);
} */