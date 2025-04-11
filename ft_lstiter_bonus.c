/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:01:53 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/11 10:41:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/* void ft_itenarate(void *content)
{
    printf("%s\n", (char *)content);
}

int main(void)
{
    t_list *head = NULL;
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    node1->content = "Hello";
    node2->content = "World";
    node3->content = "42";

    head = node3;
    node3->next = node2;
    node2->next = node1;
    node1->next = NULL;

    ft_lstiter(head, &ft_itenarate);
    free(node1);
    free(node2);
    free(node3);
}
 */