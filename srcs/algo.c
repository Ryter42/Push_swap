/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:05:55 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/30 20:43:44 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"


int	algo(t_data *data, t_list **lista, t_list **listb)
{
	mediane(data, lista, listb);
	return (0);
}

int	mediane(t_data *data, t_list **lista, t_list **listb)
{
	while (*lista)
	{
		if ((*lista)->value < data->mediane)
			push(lista, listb);
		else
		{
			push(lista, listb);
			rotate(listb);
		}
		// (*lista) = (*lista)->next;
	}
	
	return (1);	
}