/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:52:16 by elias             #+#    #+#             */
/*   Updated: 2023/06/30 15:01:52 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **lst, char c)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

t_list	*lstfindavantlast(t_list *lst)
{
	if (lst->next)
	{
		while (lst->next->next)
			lst = lst->next;
	}
	return (lst);
}
