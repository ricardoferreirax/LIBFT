/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:45:30 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/12 21:43:31 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char *set, char c)
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

static int	get_end(const char *s1, const char *set)
{
	ssize_t	len;

	len = ft_strlen(s1) - 1;
	while (len >= 0)
	{
		if (!is_in_set(set, s1[len]))
			return (len + 1);
		len--;
	}
	return (0);
}

static int	get_start(const char *s1, const char *set)
{
	int	idx;

	idx = 0;
	while (s1[idx])
	{
		if (!is_in_set(set, s1[idx]))
			return (idx);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	idx;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (start < end)
	{
		str[idx] = s1[start];
		idx++;
		start++;
	}
	str[idx] = '\0';
	return (str);
}

/* #include <stdio.h>

int	main(void)
{
	printf("String trimmed: %s\n", ft_strtrim("xxHexxlloxx", "xx"));
} */