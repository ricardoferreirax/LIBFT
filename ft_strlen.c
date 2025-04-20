/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:34:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 19:30:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

/* int main()
{
	printf("ft_strlen: %zu\n", ft_strlen("Hello World!"));
	printf("strlen: %zu\n\n", strlen("Hello World!"));

	printf("ft_strlen: %zu\n", ft_strlen("   \t\r\n\v\f-+123f"));
	printf("strlen: %zu\n\n", strlen("   \t\r\n\v\f-+123f"));

	printf("ft_strlen: %zu\n", ft_strlen(""));
	printf("strlen: %zu\n\n", strlen(""));

	printf("ft_strlen: %zu\n", ft_strlen("\0"));
	printf("strlen: %zu\n", strlen("\0"));

	// printf("\t%zu\n", strlen(NULL));
	// printf("\t%d\n", strlen(NULL)); //segfault
} */