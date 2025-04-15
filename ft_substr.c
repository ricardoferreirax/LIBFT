/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:47:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/13 20:32:29 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	idx;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	idx = 0;
	while (idx < len && s[start + idx] != '\0')
	{
		buffer[idx] = s[start + idx];
		idx++;
	}
	buffer[idx] = '\0';
	return (buffer);
}

/* int	main(void)
{
	char	*str;
	char	*substr;

	str = "Hello World";
	substr = ft_substr(str, 5, 10);
	printf("%s\n", substr);
	free (substr);
} */