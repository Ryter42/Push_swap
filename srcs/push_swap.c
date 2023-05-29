# include "../includes/push_swap.h"

int	verisign(char *nb, int i)
{
	if (ft_isdigit(nb[i + 1]) == 1)
	{
		if (i == 0 || nb[i - 1] == ' ')
			return (1);
	}
	return(0);
}

int nbverif(char *nb)
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

char	*nbcat(int av, char **ac)
{
	char	*str;
	int		i;

	i = 2;
	str = ac[1];
	while (i < av)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, ac[i]);
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
		i++;
	}
	return (nb);
}

int	veridouble(int *nb, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (nb[i] == nb[i - 1])
			return(0);
		i++;
	}
	return (1);
}

int	*getint(int av, char **ac, t_data **data)
{
	char 	*nb;

	nb = nbcat(av, ac);
	(*data)->charnb = ft_split(nb, ' ');
	(*data)->intnb= atotab((*data)->charnb);
	(*data)->nbnb = strllen((*data)->charnb);
	tritab(*data);
	if (veridouble((*data)->intnb, (*data)->nbnb) == 0)
		return(NULL);
	(*data)->mediane = (*data)->intnb[(*data)->nbnb / 2];
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

t_list	*pars(int av, char **ac, t_data **data)
{
	if (tab_nbverif(av, ac) == 0)
		return (0);
	if (!getint(av, ac, data))
		return (NULL);
	return(getlst(*data));
}

int	init(int av, char **ac, t_data **data, t_list **lista, t_list **listb)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (0);
	*listb = NULL;
	*lista = pars(av, ac, data);
	if (!*lista)
		return (0);
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

int	mediane(t_data *data, t_list *lista, t_list *listb)
{
	while (lista)
	{
		if (lista->value < data->mediane)
			push(lista, listb);
		else
			push(lista, listb);
			rotate(listb);
	}
	
	return (1);	
}

int	algo(t_data *data, t_list *lista, t_list *listb)
{
	mediane(data, lista, listb);
	return (0);
}

int	main(int av, char **ac)
{
	t_list	*lista;
	t_list	*listb;
	t_data	*data;

	if (av < 2)
		return (0);
	if (init(av, ac, &data, &lista, &listb) == 0)
		return (0);
	// algo(data, lista, listb);
	while (*(data->intnb))
	{
		printf("%d\n", *(data->intnb));
		data->intnb++;
	}
printf("mediane = %d\n", data->mediane);
	while (listb)
	{
		printf("%d\n", listb->value);
		listb = listb->next;
	}
return (0);
}
