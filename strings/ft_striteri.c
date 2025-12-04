/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:20:50 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 13:16:38 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	idx;

	if (!s || !f)
		return ;
	idx = 0;
	while (s[idx] != '\0')
	{
		f(idx, s + idx);
		idx++;
	}
}

/* void	ft_plusone(unsigned int index, char *s)
{
	*s += index;
}

#include <stdio.h>

int main()
{
	char	str[] = "aaa";
	
	printf("original str is: %s\n", str);
	ft_striteri(str, ft_plusone);
	printf("after ft_striteri: %s\n", str);
} */