/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:47:52 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/30 20:42:45 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push(t_list **list1, t_list **list2)
{
	// ft_lstadd_front(list2, list1);
	
	(*list1) = (*list1)->next;

}

void	rotate(t_list **lst)
{
	ft_lstadd_back(lst, *lst);
	(*lst) = (*lst)->next;
}

	// t_list	*temp;

	// if (!(*lst_a))
	// 	return ;
	// temp = *lst_a;
	// *lst_a = (*lst_a)->next;
	// temp->next = *lst_b;
	// *lst_b = temp;