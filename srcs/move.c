/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:47:52 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/30 15:00:40 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list **list1, t_list **list2, char c)
{
	t_list	*tmp;

	if (!(*list1))
		return ;
	tmp = *list1;
	*list1 = (*list1)->next;
	tmp->next = *list2;
	*list2 = tmp;
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_list **lst, char c)
{
	t_list	*tmp;

	if (!(*lst))
		return ;
	tmp = *lst;
	(*lst) = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 3);
}

void	revrotate(t_list **lst, char c)
{
	t_list	*temp;
	t_list	*temp_2;

	if (!(*lst))
		return ;
	temp = *lst;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp_2 = temp->next;
	temp->next = NULL;
	temp_2->next = *lst;
	*lst = temp_2;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}

void	rr(t_list **lst1, t_list **lst2)
{
	rotate(lst1, 'r');
	rotate(lst2, 'r');
}

void	rrr(t_list **lst1, t_list **lst2)
{
	revrotate(lst1, 'v');
	revrotate(lst2, 'v');
}
