/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:40:02 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/17 12:08:51 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if ((nmemb == 0 || size == 0))
		return (malloc(0));
	if (nmemb > (SIZE_MAX) / size)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, nmemb * size);
	return (buffer);
}

/* int main()
{
	int elements = 4;
	int size = 4;
	printf ("%p\n", ft_calloc(elements, size));
	printf ("%p\n", calloc(elements, size));
	
	return (0);
} */