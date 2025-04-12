/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:47:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/12 21:54:40 by rmedeiro         ###   ########.fr       */
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
	s_len = (size_t)ft_strlen(s);
	idx = 0;
	if (start + len > s_len)
		len = s_len - start;
	if (start >= s_len)
		len = 0;
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	while (idx < len && s[start + idx] != '\0')
	{
		buffer[idx] = s[start + idx];
		idx++;
	}
	buffer[idx] = '\0';
	return (buffer);
}

/* int main() 
{
    char *original = "Hello, World!";
    unsigned int start = 7; 
    size_t len = 9;      
    char *substring = ft_substr(original, start, len);
	
    printf("Original string: %s\n", original);
    printf("Substring: %s\n", substring);
    free(substring);

    return 0;
} */