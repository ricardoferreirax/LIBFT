/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:38:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:16:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int main()
{
    ft_putchar_fd('H', 1);
    ft_putchar_fd('e',1);
    ft_putchar_fd('l',1);
    ft_putchar_fd('l',1);
    ft_putchar_fd('o',1);
    ft_putchar_fd('!',1);
    ft_putchar_fd('\n',1);
} */