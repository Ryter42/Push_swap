/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:05:30 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/26 21:55:21 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

// char	*nbcat(int av, char **ac)
// {
// 	char	*str;
// 	char	*str_2;
// 	int		i;

// 	i = 2;
// 	str = ac[1];
// 	str_2 = NULL;
// 	while (i < av)
// 	{
// 		str_2 = ft_strjoin(str, " ");
// 		if (i != 2)
// 			free(str);
// 		str = ft_strjoin(str_2, ac[i]);
// 		free(str_2);
// 		i++;
// 	}
// 	return (str);
// }

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

// int	my_atoi(const char *nb)
// {
// 	int					i;
// 	int					s;
// 	long long int		nbr;
// 	char				*n;

// 	n = (char *)nb;
// 	nbr = 0;
// 	s = 1;
// 	i = 0;
// 	while ((n[i] > 6 && n[i] < 14) || n[i] == 32)
// 		i++;
// 	if (nb[i] == '-' || nb[i] == '+')
// 	{
// 		if (nb[i] == '-')
// 			s = -s;
// 		i++;
// 	}
// 	while (nb[i] > 47 && nb[i] < 58)
// 	{
// 		nbr = nbr * 10 + nb[i] - 48;
// 		i++;
// 	}
// 	if (nbr * s > 2147483647 || nbr * s < -2147483648)
// 		return (nbr * s);
// }

int	zero_num(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] == '0' || str[i] == '+' || str[i] == '-')
	{
		if (str[i] != '-')
			n++;
		i++;
	}
	return(n);
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
		if (intlen(nb[i]) + zero_num(nbr[i]) != ft_strlen(nbr[i]))
			return (free(nb), NULL);
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

