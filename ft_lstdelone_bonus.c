/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:01:36 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/09 15:01:05 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}

/* void    delete_lst(void *content)
{
	free(content);
}

int main(void)
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

	printf("Before free: %s\n", (char *)node2->content);
	ft_lstdelone(node1, &delete_lst);
	printf("After deleting node1, node3 content: %s\n", (char *)node3->content);

	ft_lstdelone(node2, &delete_lst);
	ft_lstdelone(node3, &delete_lst);

	return (0);
}
 */