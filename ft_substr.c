/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:47:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/09 09:38:32 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	s_len;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		size = s_len - start;
	else
		size = len;
	buffer = (char *)malloc((size + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (s[start + i] && i < size)
	{
		buffer[i] = s[start + i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/* int main(int argc, char **argv)
{
    if (argc == 4)
    {
        char *result = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
        if (result) 
        {
            printf("ft_substr: %s\n", result);
            free(result);
        }
    }
    return (0);
} */