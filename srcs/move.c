#include "../includes/push_swap.h"

void push(t_list *list1, t_list *list2)
{
	ft_lstadd_front(&list2, list1);
	list1 = list1->next;
}

void	rotate(t_list *lst)
{
	ft_lstadd_back(&lst, lst);
	lst = lst->next;
}