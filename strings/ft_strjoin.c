/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:22:41 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 13:16:45 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

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
		joined[idx] = s1[idx];
		idx++;
	}
	idx2 = 0;
	while (s2[idx2])
	{
		joined[idx + idx2] = s2[idx2];
		idx2++;
	}
	joined[idx + idx2] = '\0';
	return (joined);
}

/* #include <stdio.h>

int	main(void)
{
	char *a;
	
	a = ft_strjoin("We Are", "The Champions");
	printf("ft_strjoin: %s\n", a);
	free (a);
	a = ft_strjoin("We Are", "");
	printf("ft_strjoin: %s\n", a);
	free (a);
	a = ft_strjoin("", "The Champions");
	printf("ft_strjoin: %s\n", a);
	free (a);
	a = ft_strjoin("", "");
	printf("ft_strjoin: %s\n", a);
	free (a);
	a = ft_strjoin("We Are", NULL);
	printf("ft_strjoin: %s\n", a);
	free (a);
	a = ft_strjoin(NULL, "The Champions");
	printf("ft_strjoin: %s\n", a);
	free (a);

	return (0);
} */
