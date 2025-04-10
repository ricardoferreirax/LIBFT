/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:38:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/09 09:38:09 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ptr1[i] != '\0' && ptr1[i] == ptr2[i] && i < n - 1)
		i++;
	return (ptr1[i] - ptr2[i]);
}

/* int main(void)
{	
	char s1_strncmp[] = "Hello\r";
	char s2_strncmp[] = "Hello\t";
    
	printf("ft_strncmp: %d\n", ft_strncmp(s1_strncmp, s2_strncmp, 7));
	printf("strncmp: %d\n", strncmp(s1_strncmp, s2_strncmp, 7));

    return (0);
} */