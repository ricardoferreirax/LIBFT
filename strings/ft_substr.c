/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:47:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 13:17:49 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substring;
	size_t		idx;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	idx = 0;
	while (idx < len)
		substring[idx++] = s[start++];
	substring[idx] = '\0';
	return (substring);
}

/* int	main(void)
{
	char	*str;
	char	*substr;

	str = "Hello World";
	substr = ft_substr(str, 6, 10);
	printf("%s\n", substr);
	free (substr);
} */