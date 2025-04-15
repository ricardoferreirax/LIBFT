/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:41:47 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/14 10:03:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp_s;
	size_t			idx;

	tmp_s = (const unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		if (tmp_s[idx] == (unsigned char)c)
			return ((void *)(tmp_s + idx));
		idx++;
	}
	return (NULL);
}

/* int	main(void)
{
	const char s[] = "Hello, World!";;
	char *resultado;

	resultado = ft_memchr(s, 'e', ft_strlen(s));
	printf("%s\n", resultado);
	return (0);
} */
