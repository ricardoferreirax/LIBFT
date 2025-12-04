/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:45:30 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 13:17:43 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

static int	ft_isset(char c, const char *set)
{
	int	idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	idx;
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	trimmed = malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	idx = 0;
	while (start < end)
		trimmed[idx++] = s1[start++];
	trimmed[idx] = '\0';
	return (trimmed);
}

/* #include <stdio.h>

int	main(void)
{
	char *a;
	
	a = ft_strtrim("Hello World!", "He");
	printf("ft_strtrim: %s\n", a); 
	free (a);
	a = ft_strtrim("\\nHello World\\n", "\\n");
	printf("ft_strtrim: %s\n", a); 
	free (a);
	a = ft_strtrim("xxHelloxxWorldxx", "xx");
	printf("ft_strtrim: %s\n", a); 
	free (a);
	a = ft_strtrim("Hello", NULL);
	printf("ft_strtrim: %s\n", a); 
	free (a);
	a = ft_strtrim(NULL, "World");
	printf("ft_strtrim: %s\n", a); 
	free (a);

	return (0);
} */