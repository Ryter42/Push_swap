# include "../includes/push_swap.h"

// int	listinit

int nbverif(char *nb)
{
	int	i;

	i = 0;
	while (i < ft_strlen(nb))
	{
		if (ft_isdigit(nb[i]) == 0 && nb[i] != ' ')
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

char	*nbcat(int av, char **ac)
{
	char	*str;
	int		i;

	i = 2;
	str = ac[1];
	while (i < av)
	{
		str = ft_strjoin(str, ac[i]);
		str = ft_strjoin(str, " ");
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

int	*getint(int av, char **ac)
{
	char 	*nb;
	char 	**nbr;
	int		*nombre;

	nb = nbcat(av, ac);
	nbr = ft_split(nb, ' ');
	nombre = atotab(nbr);

	return (nombre);
}

int	*pars(int av, char **ac, t_data *data)
{
	// t_list tmp;
	// t_list lst;
	int	*nb;

	(void)data;
	if (tab_nbverif(av, ac) == 0)
		return (0);
	nb = getint(av, ac);
	return(nb);
}

int	main(int av, char **ac)
{
	// t_list *liste_a;
	// t_list *liste_b;
	t_data data;
	int	*nb = pars(av, ac, &data);
	while (*nb)
	{
		printf("%d\n", *nb);
		nb++;
	}
return (0);
}