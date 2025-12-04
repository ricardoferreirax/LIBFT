/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:14:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:18:54 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include "unistd.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int nb);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *str);

#endif