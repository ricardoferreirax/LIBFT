/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:00:18 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/10 11:36:42 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int main()
{
	t_list *list = NULL;

	ft_lstadd_front(&list, ft_lstnew("primeiro"));
	ft_lstadd_front(&list, ft_lstnew("segundo"));
	ft_lstadd_front(&list, ft_lstnew("terceiro"));

	while (list != NULL)
	{
		printf("%s -> ", (char *)list->content);
		list = list->next;
	}
	printf("NULL\n");
	return (0);
} */