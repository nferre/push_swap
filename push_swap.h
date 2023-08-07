/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:49:23 by nferre            #+#    #+#             */
/*   Updated: 2021/11/18 13:11:44 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int	size;
	int	*tab;
	int	*qn;
	int	size_tab;
	int	chunk;
}	t_list;

void	check_if_empty(int argc, char **argv);
void	push_last(t_list *a, t_list *b);
char	**ft_split(char const *s, char c);
void	rotate(t_list *list, int j);
void	swap(t_list *list, int i);
int		ft_atoi(const char *str);
int		verify_params(int argc, char **argv);
void	push(t_list *a, t_list *b, int i);
void	r_rotate(t_list *a, int j);
int		get_max(t_list *a);
int		get_pos_max(t_list *a);
void	sort(t_list *a, t_list *b);
void	print_tab(int *tab, int size);
int		get_min(t_list *a);
int		get_pos_min(t_list *a);
void	sort_tab(int *tab, int size);
void	find_median(int *tab, int size, t_list *a);
void	find_median500(int *tab, int size, t_list *a);
void	sort_3(t_list *a);
void	sort_5(t_list *a, t_list *b);
int		is_sorted(t_list *a);
int		verify_char(char **argv);
void	ft_swap(int *a, int *b);

#endif
