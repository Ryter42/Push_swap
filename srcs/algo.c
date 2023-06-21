/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:05:55 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/21 23:14:09 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

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
		return(sup);
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


int	calculator(t_data *data, t_list *lista, t_list *listb)
{
	int	res;
	int	value;
	int	indexb;

	res =  2147483647;// a changer mdr
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

void	gotop(t_list **lst, int value, char c)
{
	while (findindex(*lst, value) != 1)
	{
		if (findindex(*lst, value) < ft_lstsize(*lst) / 2 || ft_lstsize(*lst) <= 2)
			rotate(lst, c);
		else
			revrotate(lst, c);
	}

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

void	tri_3(t_data *data, t_list **lst)
{
	if ((*lst)->value == data->intnb[data->nbnb - 1])
		rotate(lst, 'a');
	if ((*lst)->next->value == data->intnb[data->nbnb - 1])
		revrotate(lst, 'a');
	if ((*lst)->value > (*lst)->next->value)
		swap(lst, 'a');
}

void tri_4(t_data *data, t_list **lsta, t_list **lstb)
{
	gotop(lsta, data->intnb[0], 'a');
	push(lsta, lstb, 'b');
	tri_3(data, lsta);
	push(lstb, lsta, 'a');

}

void tri_5(t_data *data, t_list **lsta, t_list **lstb)
{
	gotop(lsta, data->intnb[0], 'a');
	push(lsta, lstb, 'b');
	gotop(lsta, data->intnb[1], 'a');
	push(lsta, lstb, 'b');
	tri_3(data, lsta);
	push(lstb, lsta, 'a');
	push(lstb, lsta, 'a');
}

void algo(t_data *data, t_list **lista, t_list **listb)
{
	if (data->nbnb == 2)
		swap(lista, 'a');
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
	push(listb, lista, 'a');
	while(ft_lstsize(*listb) != 0)
	{
		value  = calculator(data, *lista, *listb);
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

void	mediane(t_data *data, t_list **lista, t_list **listb)
{
	while (*lista)
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