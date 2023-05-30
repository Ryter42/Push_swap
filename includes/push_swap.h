/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:47:56 by emoreau           #+#    #+#             */
/*   Updated: 2023/05/30 20:35:59 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

typedef struct s_data
{
	// t_list	*lista;
	// t_list	*listb;
	char **charnb;
	int	*intnb;
	int	nbnb;
	int	mediane;
}	t_data;

void	tritab(t_data *data);
int		tritabverif(t_data *data);
void	push(t_list **list1, t_list **list2);
void	rotate(t_list **lst);
int		veridouble(int *nb, int size);
int		algo(t_data *data, t_list **lista, t_list **listb);
char	*nbcat(int av, char **ac);
int		strllen(char **str);
int		*atotab(char **nbr);
int		verisign(char *nb, int i);
int 	nbverif(char *nb);
int		mediane(t_data *data, t_list **lista, t_list **listb);
int		init(int av, char **ac, t_data **data, t_list **lista, t_list **listb);
int		*getint(int av, char **ac, t_data **data);
t_list 	*getlst(t_data *data);
int		tab_nbverif(int av, char **ac);
t_list	*pars(int av, char **ac, t_data **data);


#endif