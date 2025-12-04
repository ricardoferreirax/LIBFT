/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:13:42 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:37:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

// # include "../memory/memory.h"
# include "stdbool.h"
# include "stdlib.h"
# include "unistd.h"

int				ft_atoi(const char *s);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int b);
int	             ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *src);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *scr, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
char			*ft_strrchr(const char *a, int b);
char			*ft_strtrim(const char *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strcpy(char *dest, const char *src);

#endif