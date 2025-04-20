/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:43:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 19:48:13 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		idx;
	char	*last;

	idx = 0;
	last = NULL;
	while (s[idx] != '\0')
	{
		if (s[idx] == (char)c)
			last = (char *)(s + idx);
		idx++;
	}
	if ((char)c == '\0')
		return ((char *)(s + idx));
	return (last);
}

/* #include <stdio.h>

int	main(void)
{
	printf("ft_strrchr: %s\n", ft_strrchr("Hello World!", 'o'));
	printf("strrchr: %s\n\n", strrchr("Hello World!", 'o'));
	
	printf("ft_strrchr: %s\n", ft_strrchr("Hello World!", ' '));
	printf("strrchr: %s\n\n", strrchr("Hello World!", ' '));

	printf("ft_strrchr: %s\n", ft_strrchr("Hello World!", 'l'));
	printf("strrchr: %s\n\n", strrchr("Hello World!", 'l'));

	printf("ft_strrchr: %s\n", ft_strrchr("Hello World!", '\0'));
	printf("strrchr: %s\n", strrchr("Hello World!", '\0'));

	// printf("\t%s\n", ft_strrchr(NULL, '!'));

	return (0);
} */