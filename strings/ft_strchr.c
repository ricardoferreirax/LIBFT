/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:14:22 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 13:16:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strchr(const char *s, int c)
{
	int		idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
		idx++;
	}
	if ((char)c == '\0')
		return ((char *)(s + idx));
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	printf("ft_strchr: %s\n", ft_strchr("Hello World!", 'o'));
	printf("strchr: %s\n\n", strchr("Hello World!", 'o'));
	
	printf("ft_strchr: %s\n", ft_strchr("Hello World!", ' '));
	printf("strchr: %s\n\n", strchr("Hello World!", ' '));

	printf("ft_strchr: %s\n", ft_strchr("Hello World!", 'd'));
	printf("strchr: %s\n\n", strchr("Hello World!", 'd'));

	printf("ft_strchr: %s\n", ft_strchr("Hello World!", '\0'));
	printf("strchr: %s\n", strchr("Hello World!", '\0'));

	// printf("\t%s\n", ft_strchr(NULL, '!'));

	return (0);
} */