/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:39:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 16:56:34 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	start;

	if (*little == '\0')
		return ((char *)big);
	start = 0;
	while (start < len && big[start] != '\0')
	{
		idx = 0;
		while (little[idx] && big[start + idx] == little[idx]
			&& (start + idx) < len)
			idx++;
		if (little[idx] == '\0')
			return ((char *)&big[start]);
		start++;
	}
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strnstr("ricardo", "ar", 5));
} */