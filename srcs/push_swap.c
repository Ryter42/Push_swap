# include "../includes/push_swap.h"

// int	listinit

int nbverif(char *nb)
{
	int	i;

	i = 0;
	while (i < ft_strlen(nb))
	{
		if (ft_isdigit(nb[i]))
			return (0);
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

int	pars(int av, char **ac, t_data *data)
{
	// t_list tmp;
	// t_list lst;
	data->value = tab_nbverif(av, ac);
	return(1);
}

int	main(int av, char **ac)
{
	// t_list *liste_a;
	// t_list *liste_b;
	t_data *data = NULL;
	printf("%d", pars(av, ac, data));
return (0);
}