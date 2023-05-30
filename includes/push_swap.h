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
int	tritabverif(t_data *data);
void push(t_list *list1, t_list *list2);
void	rotate(t_list *lst);


#endif