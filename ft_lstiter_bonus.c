/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:01:53 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/20 16:54:03 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

int main(void)
{
    t_list *list = NULL;

    ft_lstadd_back(&list, ft_lstnew(strdup("primeiro")));
    ft_lstadd_back(&list, ft_lstnew(strdup("segundo")));
    ft_lstadd_back(&list, ft_lstnew(strdup("terceiro")));

    ft_lstiter(list, print_content);

    while (list != NULL)
    {
        t_list *temp = list;
        list = list->next;
        free(temp->content);
        free(temp);
    }
    return 0;
} */