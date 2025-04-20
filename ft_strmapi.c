/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:34:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/17 13:16:07 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*str;
	unsigned int	idx;

	if (!s || !f)
		return (NULL);
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	idx = 0;
	while (s[idx] != '\0')
	{
		str[idx] = f(idx, s[idx]);
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

/* #include <stdio.h>

char	ft_ctoupper(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	index *= 1;
	return (c);
}

int	main(void)
{
	char str[] = "abcdefg";

	printf("Before: %s\n", str);
	printf("After: %s\n", ft_strmapi(str, ft_ctoupper));
	return (0);
} */
