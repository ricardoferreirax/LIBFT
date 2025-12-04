/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:38:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 13:17:23 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	if (n == 0)
		return (0);
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	idx = 0;
	while (tmp_s1[idx] && tmp_s2[idx] && tmp_s1[idx] == tmp_s2[idx]
		&& idx < n - 1)
		idx++;
	return (tmp_s1[idx] - tmp_s2[idx]);
}

/* int main(void)
{	
	printf("ft_strncmp: %d\n", ft_strncmp("ABC", "ABC", 3));
	printf("strncmp: %d\n\n", strncmp("ABC", "ABC", 3));

	printf("ft_strncmp: %d\n", ft_strncmp("ABC", "ABC", 2));
	printf("strncmp: %d\n\n", strncmp("ABC", "ABC", 2));
	
	printf("ft_strncmp: %d\n", ft_strncmp("ABC", "ABC", 0));
	printf("strncmp: %d\n\n", strncmp("ABC", "ABC", 0));

	printf("ft_strncmp: %d\n", ft_strncmp("ABC", "AB", 3));
	printf("strncmp: %d\n", strncmp("ABC", "AB", 3));

	// printf("\t%d\n", ft_strncmp("ABC", NULL, 3)); //segfault
	// printf("\t%d\n", ft_strncmp(NULL, "ABC", 3)); //segfault
	// printf("\t%d\n", ft_strncmp(NULL, NULL, 3)); //segfault

    return (0);
} */