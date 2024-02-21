/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:29 by emoreau           #+#    #+#             */
/*   Updated: 2024/02/11 02:35:33 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mediane(t_data *data, t_list **lista, t_list **listb)
{
	while (ft_lstsize(*lista) > 1)
	{
		if ((*lista)->value <= data->mediane)
			push(lista, listb, 'b');
		else
		{
			push(lista, listb, 'b');
			rotate(listb, 'b');
		}
	}
}

int	findsup(t_data *data, t_list *lst, int v)
{
	int	sup;

	sup = data->intnb[data->nbnb - 1];
	while (lst)
	{
		if (lst->value > v && lst->value < sup)
			sup = lst->value;
		lst = lst->next;
	}
	return (sup);
}

int	findindex(t_list *lst, int value)
{
	int	i;

	i = 1;
	while (lst->value != value)
	{
		lst = lst->next;
		if (!lst)
			return (0);
		i++;
	}
	return (i);
}

void	gotop(t_list **lst, int value, char c)
{
	while (findindex(*lst, value) != 1)
	{
		if (findindex(*lst, value) < ft_lstsize(*lst) / 2
			|| ft_lstsize(*lst) <= 2)
			rotate(lst, c);
		else
			revrotate(lst, c);
	}
}
