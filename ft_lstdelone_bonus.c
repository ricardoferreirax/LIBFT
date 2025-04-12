/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:01:36 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/12 14:09:44 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

/* int main(void)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (1);
	node->content = strdup("Hello");
	node->next = NULL;

	printf("Before deletion: %s\n", (char *)node->content);
	ft_lstdelone(node, &free);
	printf("After deletion\n");

	return (0);
} */