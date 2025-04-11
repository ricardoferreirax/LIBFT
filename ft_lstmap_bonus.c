/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:02:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/11 15:15:38 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;
	void	*failsafe;

	if (!f || !lst || !del)
		return (NULL);
	new_list = NULL;
	failsafe = NULL;
	while (lst != NULL)
	{
		failsafe = f(lst->content);
		node = ft_lstnew(failsafe);
		if (node == NULL)
		{
			del(failsafe);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}

/* void *iterate(void *content)
{
    int *num = (int *)content;
    return (num);
}
    
void del_int(void *content)
{
    free(content);
}

int main()
{
    int content1 = 22;
    int content2 = 32;
    int content3 = 42;

    t_list *elem1 = ft_lstnew(&content1);
    t_list *elem2 = ft_lstnew(&content2);
    t_list *elem3 = ft_lstnew(&content3);

    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = NULL;

    t_list *mapped_list = ft_lstmap(elem1, &iterate, &del_int);

    while (mapped_list != NULL)
    {
        printf("%d\n", *(int *)(mapped_list->content));
        mapped_list = mapped_list->next;
    }
    
    ft_lstclear(&elem1, &del_int);
    ft_lstclear(&mapped_list, &del_int);
	free(elem1);
	free(elem2);
	free(elem3);
    return 0;
} */