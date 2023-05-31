/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:47:52 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/31 18:26:16 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push(t_list **list1, t_list **list2)
{
	t_list *tmp;

	if (!(*list1))
		return ;
	tmp = *list1;
	*list1 = (*list1)->next;
	tmp->next = *list2;
	*list2 = tmp;
}

void	rotate(t_list **lst)
{
	t_list *tmp;

	if (!(*lst))
		return ;
	tmp = *lst;
	(*lst) = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
}

void	swap(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;

}

void	revrotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = lstfindavantlast(*lst);
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *lst;
	*lst = tmp2;

}

void	rr(t_list **lst1, t_list **lst2)
{
	rotate(lst1);
	rotate(lst2);
}

void	rrr(t_list *lst1, t_list *lst2)
{
	revrotate(&lst1);
	revrotate(&lst2);
}
