/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:38:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 16:27:45 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	char s1_strncmp[] = "Hello\r";
	char s2_strncmp[] = "Hello\t";
    
	printf("ft_strncmp: %d\n", ft_strncmp(s1_strncmp, s2_strncmp, 7));
	printf("strncmp: %d\n", strncmp(s1_strncmp, s2_strncmp, 7));

    return (0);
} */