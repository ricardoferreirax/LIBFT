/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:22:41 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/11 11:09:55 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (buffer);
}

/* int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("Original string: %s\n", argv[1]);
		printf("Original string: %s\n", argv[2]);
		printf("Joined string: %s\n", ft_strjoin(argv[1], argv[2]));
	}
	return (0);
} */