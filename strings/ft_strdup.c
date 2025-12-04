/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:17:38 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 13:16:32 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		idx;

	idx = 0;
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[idx] != '\0')
	{
		dest[idx] = s[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

/* int main()
{
	char *my_dest = "Hello";
	char *orig_dest = "Hello";
	char *src = "World";
	my_dest = ft_strdup(src);
	orig_dest = strdup(src);
	printf("ft_strdup: %s\n", my_dest);
	printf("strdup: %s\n", orig_dest);
	free(my_dest);
	free(orig_dest);
	
	return (0);
} */