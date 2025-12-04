/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:21:10 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:17:15 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	idx;

	if (!s || fd < 0)
		return ;
	idx = 0;
	while (s[idx] != '\0')
		write(fd, &s[idx++], 1);
}

/* int	main()
{
	ft_putstr_fd("Hello", 1);
	return (0);
} */