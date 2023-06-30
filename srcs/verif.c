/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:06:31 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/30 15:15:57 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	veridouble(int *nb, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (nb[i] == nb[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	tritabverif(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->nbnb)
	{
		if (data->intnb[i - 1] > data->intnb[i])
			return (0);
		i++;
	}
	return (1);
}

int	verisign(char *nb, int i)
{
	if (ft_isdigit(nb[i + 1]) == 1)
	{
		if (i == 0 || nb[i - 1] == ' ')
			return (1);
	}
	return (0);
}

int	nbverif(char *nb)
{
	int	i;

	i = 0;
	while (i < ft_strlen(nb))
	{
		if (ft_isdigit(nb[i]) == 0 && nb[i] != ' ')
		{
			if (nb[i] != '+' || nb[i] != '-')
			{
				if (verisign(nb, i) == 0)
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}
