/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:20:17 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/09 09:37:14 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(const char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] != sep && str[i] != '\0')
		i++;
	return (i);
}

static int	count_words(const char *str, char sep)
{
	int	i;
	int	words;
	int	current_word;

	i = 0;
	words = 0;
	current_word = 0;
	while (str[i] != '\0')
	{
		if (!current_word && ft_isprint(str[i]) && str[i] != sep)
		{
			words++;
			current_word = 1;
		}
		if (current_word && str[i] == sep)
			current_word = 0;
		i++;
	}
	return (words);
}

void	free_split(char **array, int current)
{
	while (current >= 0)
		free(array[current--]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	char	**array;

	words = count_words(s, c);
	array = (char **) malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		array[i] = (char *) malloc((word_len(s, c) + 1) * sizeof(char));
		if (array[i] == NULL)
		{
			free_split(array, i);
			return (NULL);
		}
		ft_strlcpy(array[i], s, word_len(s, c) + 1);
		s += word_len(s, c) + 1;
		i++;
	}
	array[i] = NULL;
	return (array);
}
