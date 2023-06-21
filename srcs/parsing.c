/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:05:30 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/21 13:23:13 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

char	*nbcat(int av, char **ac)
{
	char	*str;
	char	*str2;
	char	*tmp;
	int		i;

	i = 2;
	tmp = ac[1];
	str2 = " ";
	str = ft_strjoin(tmp, str2);
	while (i < av)
	{
		str2 = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(str2, ac[i]);
		free(str2);
		i++;
	}
	return (str);
}

int	strllen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	intlen(int	i)
{
	int res;

	if (i < 0)
		res = 2;
	else
		res = 1;
	while (i > 10 || i < -10)
	{
		i = i / 10;
		res++;
	}
	return (res);
}

int	*atotab(char **nbr)
{
	int	*nb;
	int	i;

	i = 0;
	nb = malloc(sizeof(int *) * strllen(nbr));
	if (!nb)
		return (NULL);
	while (nbr[i])
	{
		nb[i] = ft_atoi(nbr[i]);
		if (intlen(nb[i]) != ft_strlen(nbr[i]))
			return (NULL);
		i++;
	}
	return (nb);
}

void	tritab(t_data *data)
{
	int	tmp;
	int	i;

	i = 0;
	while (tritabverif(data) == 0)
	{
		while (i < data->nbnb - 1)
		{
			if (data->intnb[i] > data->intnb[i + 1])
			{
				tmp = data->intnb[i];
				data->intnb[i] = data->intnb[i + 1];
				data->intnb[i + 1] = tmp;
			}
			i++;
		}
		i = 0;
	}
}

