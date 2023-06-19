/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:05:30 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/19 15:57:09 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

 char    *ft_strjoin2(char const *s1, char *s2)
{
    char    *str;
    size_t    i;
    size_t    j;

    if (!s1)
        s1 = ft_calloc(sizeof(char), 1);
    if (!s2)
        return (NULL);
    j = 0;
    str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
} 

char	*nbcat(int av, char **ac)
{
	char	*str;
	char	*str_2;
	int		i;

	i = 2;
	str = ac[1];
	str_2 = NULL;
	while (i < av)
	{
		str_2 = ft_strjoin2(str, " ");
		free(str);
		str = ft_strjoin2(str_2, ac[i]);
		free(str_2);
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
	nb = malloc(sizeof(int) * strllen(nbr));
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

