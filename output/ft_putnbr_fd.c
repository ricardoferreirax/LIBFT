/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:44:04 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:17:09 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

/* int main()
{
    ft_putnbr_fd(-56789, 1);
    printf("\n");
    ft_putnbr_fd(1234, 1);
    printf("\n");
    ft_putnbr_fd(0, 1);
    printf("\n");
    ft_putnbr_fd(-2147483648, 1);
    printf("\n");
    ft_putnbr_fd(2147483647, 1);
    printf("\n");
} */