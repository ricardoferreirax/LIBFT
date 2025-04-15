/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:45:30 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/13 15:06:00 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	idx;

	idx = 0;
	while (set[idx])
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	int		start;
	int		end;
	int		idx;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = (int)ft_strlen(s1);
	while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed = malloc((end - start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	idx = 0;
	while (start < end)
		trimmed[idx++] = s1[start++];
	trimmed[start] = '\0';
	return (trimmed);
}

/* #include <stdio.h>

int	main(void)
{
	printf("String trimmed: %s\n", ft_strtrim("xxHexxlloxx", "xx"));
} */