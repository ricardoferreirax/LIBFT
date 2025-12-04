/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:00:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:24:47 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = tmp;
	}
	*lst = NULL;
}

/* int main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	if (!node1 || !node2 || !node3)
		return (1);

	node1->content = strdup("Hello");
	node2->content = strdup("World");
	node3->content = strdup("42");

	node3->next = node2;
	node2->next = node1;
	node1->next = NULL;

	printf("Before clear: %s\n", (char *)node2->content);
	ft_lstclear(&node3, &free);
	printf("After clearing list\n");

	return (0);
} */