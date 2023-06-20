/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:00:57 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/20 15:29:08 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int	init(int av, char **ac, t_data **data, t_list **lista, t_list **listb)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (0);
	*listb = NULL;
	*lista = pars(av, ac, data);
	if (!*lista)
		return (0);
	tritab(*data);
	if (veridouble((*data)->intnb, (*data)->nbnb) == 0)
		return(0);
	(*data)->mediane = (*data)->intnb[(*data)->nbnb / 2];
	return (1);
}

int	*getint(int av, char **ac, t_data **data)
{
	char 	*nb;

	nb = nbcat(av, ac);
	(*data)->charnb = ft_split(nb, ' ');
	(*data)->intnb= atotab((*data)->charnb);
	(*data)->nbnb = strllen((*data)->charnb);
	free(nb);
	return ((*data)->intnb);
}

t_list *getlst(t_data *data)
{
	t_list	*lista;
	t_list	*tmp;
	int	i;

	i = 1;
	lista = lstnewint(data->intnb[0]);
	while (i < data->nbnb)
	{
		tmp = lstnewint(data->intnb[i]);
		ft_lstadd_back(&lista, tmp);
		i++;
	}
	return (lista);
}

int	tab_nbverif(int av, char **ac)
{
	int	i;

	i = 1;
	while (i < av)
	{
		if (nbverif(ac[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

t_list	*pars(int av, char **ac, t_data **data)
{
	if (!getint(av, ac, data) || tab_nbverif(av, ac) == 0)
		return (NULL);
	// if (!getint(av, ac, data))
	// 	return (NULL);
	return(getlst(*data));
}

// t_list	*pars(int av, char **ac, t_data **data)
// {
// 	if (tab_nbverif(av, ac) == 0)
// 		return (0);
// 	if (!getint(av, ac, data))
// 		return (NULL);
// 	return(getlst(*data));
// }
