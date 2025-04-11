#include "libft.h"

void *iterate(void *content)
{
    int *num = (int *)content;
    return (num);
}

int ft42_toupper(void *c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
    
void del_int(void *content)
{
    free(content);
}
int main()
{
    t_list *list = NULL;
    t_list *new_list;
    t_list *temp;
    t_list  *node_1 = ft_lstnew("p");
    t_list  *node_2 = ft_lstnew("s");
    t_list  *node_3 = ft_lstnew("t");

    ft_lstadd_back(&list, node_1);
    ft_lstadd_back(&list, node_2);
    ft_lstadd_back(&list, node_3);

    new_list = ft_lstmap(list, &ft42_toupper, &del_int);

    temp = new_list;
    while(temp != NULL)
    {
        printf("temp content -> %s\n",(char * )temp->content);
        temp = temp->next;
    }
    temp =new_list;
    printf("content 1-> %s\n", (char *)temp->content);
    temp = temp->next;
    printf("content 2-> %s\n", (char *)temp->content);
    temp = temp->next;
    printf("content 3-> %s\n", (char *)temp->content);
    temp = temp->next;
    if(temp)
        printf("last -> %s\n", (char *)temp->content);
    temp = new_list;
    temp = temp->next;
    temp = temp->next;
    printf("content 3 again-> %s\n", (char *)temp->content);
    printf("content 1 again because we are printing the original list-> %s\n", (char *)new_list->content);
}
