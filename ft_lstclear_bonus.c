/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:00:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/10 11:37:19 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		(*del)(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

/* void delete_lst(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	if (!node1 || !node2 || !node3)
		return (1);

	node1->content = strdup("Hello");
	node2->content = strdup("World");
	node3->content = strdup("42");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("Before free: %s\n", (char *)node2->content);
	ft_lstclear(&node1, &delete_lst);
} */