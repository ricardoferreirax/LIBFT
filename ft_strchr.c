/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:14:22 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/17 13:01:47 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
		idx++;
	}
	if ((char)c == '\0')
		return ((char *)(s + idx));
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	printf("ft_strchr: %s\n", ft_strchr("ricardo", 'r'));
	printf("strchr: %s\n", strchr("ricardo", 'r'));

	return (0);
} */