/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:34:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/09 09:38:04 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*buffer;
	unsigned int	i;

	i = 0;
	buffer = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (s[i] != '\0')
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/* char function_f_mapi(unsigned int i, char c)
{
        (void)i;
        return(c + 1);
}

int main()
{
    char *str_strmapi = "Hello, World!";
    char *result_strmapi = ft_strmapi(str_strmapi, function_f_mapi);
    
    printf("Origial: %s\n", str_strmapi);
    printf("New: %s\n", result_strmapi);
    free(result_strmapi);
} */