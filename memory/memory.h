/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:12:26 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:12:44 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "stdint.h"
# include "stdlib.h"
# include "unistd.h"
# include <string.h>

void	ft_bzero(void *a, size_t i);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *a, int b, size_t c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t i);
void	*ft_memmove(void *dest, const void *src, size_t i);
void	*ft_memset(void *a, int c, size_t i);

#endif