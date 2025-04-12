/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:50:51 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/12 13:52:38 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("ft_isascii(%c): %i\n", argv[1][0], ft_isascii(argv[1][0]));
	return (0);
} */
