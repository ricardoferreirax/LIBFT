/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:03:41 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/10 11:29:26 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*buffer;

	if (lst == NULL)
		return (0);
	i = 0;
	buffer = lst;
	while (buffer != NULL)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
}

/* int main()
{
	t_list *list = NULL;

	ft_lstadd_front(&list, ft_lstnew("primeiro"));
	ft_lstadd_front(&list, ft_lstnew("segundo"));
	ft_lstadd_front(&list, ft_lstnew("terceiro"));
	
	printf("%d\n", ft_lstsize(list));
	return (0);
} */