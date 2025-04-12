/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:20:17 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/12 16:03:18 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(const char *str, char sep)
{
	int	idx;

	idx = 0;
	while (str[idx] != sep && str[idx] != '\0')
		idx++;
	return (idx);
}

static int count_words(const char *str, char sep)
{
	int idx;
	int count;
	int in_word;

	idx = 0,
	count = 0;
	in_word = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] != sep && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		if (str[idx] == sep)
			in_word = 0;
		idx++;
	}
	return (count);
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
	int		idx;
	char	**array;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **) malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	idx = 0;
	while (idx < words)
	{
		while (*s == c)
			s++;
		array[idx] = (char *) malloc((word_len(s, c) + 1) * sizeof(char));
		if (array[idx] == NULL)
			return (free_split(array, idx), NULL);
		ft_strlcpy(array[idx], s, word_len(s, c) + 1);
		s += word_len(s, c) + 1;
		idx++;
	}
	array[idx] = NULL;
	return (array);
}

/* #include <stdio.h>

int main(void)
{
    char const *str_split = "Hello World";
    char sep_split = ' ';
    char **result_split = ft_split(str_split, sep_split);

    int i = 0;
	int j = 0;
    while (result_split[i])
    {
        printf("Print: %s\n", result_split[i]);
        i++;
    }
    while (result_split[j])
    {
        free(result_split[j]);
        j++;
    }
    free(result_split);
    return (0);
}
 */