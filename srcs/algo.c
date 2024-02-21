/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:05:55 by emoreau           #+#    #+#             */
/*   Updated: 2024/02/11 00:50:44 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tri_3(t_data *data, t_list **lst)
{
	if ((*lst)->value == data->intnb[data->nbnb - 1])
		rotate(lst, 'a');
	if ((*lst)->next->value == data->intnb[data->nbnb - 1])
		revrotate(lst, 'a');
	if ((*lst)->value > (*lst)->next->value)
		swap(lst, 'a');
}

void	tri_4(t_data *data, t_list **lsta, t_list **lstb)
{
	gotop(lsta, data->intnb[0], 'a');
	push(lsta, lstb, 'b');
	tri_3(data, lsta);
	push(lstb, lsta, 'a');
}

void	tri_5(t_data *data, t_list **lsta, t_list **lstb)
{
	gotop(lsta, data->intnb[0], 'a');
	push(lsta, lstb, 'b');
	gotop(lsta, data->intnb[1], 'a');
	push(lsta, lstb, 'b');
	tri_3(data, lsta);
	push(lstb, lsta, 'a');
	push(lstb, lsta, 'a');
}

void	algo(t_data *data, t_list **lista, t_list **listb)
{
	if (data->nbnb == 2)
		rotate(lista, 'a');
	else if (data->nbnb == 3)
		tri_3(data, lista);
	else if (data->nbnb == 4)
		tri_4(data, lista, listb);
	else if (data->nbnb == 5)
		tri_5(data, lista, listb);
	else
		algotri(data, lista, listb);
}

void	algotri(t_data *data, t_list **lista, t_list **listb)
{
	int	value;

	mediane(data, lista, listb);
	// push(listb, lista, 'a');
	while (ft_lstsize(*listb) != 0)
	{
		value = calculator(data, *lista, *listb);
		gotop(listb, value, 'b');
		if ((*listb)->value > suplst(data, *lista))
		{
			gotop(lista, minlst(data, *lista), 'a');
			push(listb, lista, 'a');
		}
		else
		{
			gotop(lista, findsup(data, *lista, value), 'a');
			push(listb, lista, 'a');
		}
	}
	gotop(lista, data->intnb[0], 'a');
}
