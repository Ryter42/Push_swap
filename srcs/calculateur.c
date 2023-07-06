/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caluculateur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:08:31 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/30 15:11:46 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculator(t_data *data, t_list *lista, t_list *listb)
{
	int	res;
	int	value;
	int	indexb;

	res = 2147483647;
	indexb = 1;
	if (suplst(data, lista) < minlst(data, listb))
		return (listb->value);
	while (listb)
	{
		if (nbrcoup(data, lista, listb, indexb) < res)
		{
			res = nbrcoup(data, lista, listb, indexb);
			value = listb->value;
		}
		indexb++;
		listb = listb->next;
	}
	return (value);
}

int	nbrcoup(t_data *data, t_list *lista, t_list *listb, int ib)
{
	int	sup;
	int	i;

	sup = findindex(lista, findsup(data, lista, listb->value));
	if (ib < ft_lstsize(listb) / 2)
	{
		if (sup < ft_lstsize(lista) / 2)
			i = sup + ib;
		else
			i = ft_lstsize(lista) - sup + ib;
	}
	else
	{
		if (sup < ft_lstsize(lista) / 2)
			i = sup + ft_lstsize(listb) - ib;
		else
			i = ft_lstsize(lista) - sup + ft_lstsize(listb) - ib;
	}
	return (i);
}

int	suplst(t_data *data, t_list *lst)
{
	int	i;

	i = data->intnb[0];
	while (lst)
	{
		if (lst->value > i)
			i = lst->value;
		lst = lst->next;
	}
	return (i);
}

int	minlst(t_data *data, t_list *lst)
{
	int	i;

	i = data->intnb[data->nbnb - 1];
	while (lst)
	{
		if (lst->value < i)
			i = lst->value;
		lst = lst->next;
	}
	return (i);
}
