/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:02:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/04 14:25:06 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	if (!f || !lst || !del)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmp);
		lst = lst->next;
	}
	return (newlst);
}

/* void *ft_strdup_wrapper(void *content)
{
    return ft_strdup((char *)content); 
}

int main(void)
{
    t_list *list = NULL;
    t_list *node1 = ft_lstnew(strdup("1"));
    t_list *node2 = ft_lstnew(strdup("2"));
    t_list *node3 = ft_lstnew(strdup("3"));

    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);

    t_list *new_list = ft_lstmap(list, ft_strdup_wrapper, free);

    while (new_list != NULL)
    {
        printf("%s\n", (char *)new_list->content);
        new_list = new_list->next;
    }
    ft_lstclear(&list, free);

    return 0;
} */
