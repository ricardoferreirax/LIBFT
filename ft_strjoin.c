/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:22:41 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/13 14:41:15 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	idx;
	size_t	idx2;

	if (!s1 || !s2)
		return (NULL);
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	idx2 = 0;
	while (s2[idx2])
	{
		dest[idx + idx2] = s2[idx2];
		idx2++;
	}
	dest[idx + idx2] = '\0';
	return (joined);
}


/* #include <stdio.h>

int	main(void)
{
	char *s1 = "We Are ";
	char *s2 = "The Champions!";

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("ft_strjoin: %s\n", ft_strjoin(s1, s2));

	return (0);
} */
