/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:26:57 by nferre            #+#    #+#             */
/*   Updated: 2021/11/08 10:50:49 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_b(t_list *a, t_list *b)
{
	while (b->size != 0)
	{
		if (b->tab[b->size - 1] == get_max(b))
		{
			push(b, a, 0);
			continue ;
		}
		else
		{
			if (get_pos_max(b) > b->size / 2)
				while (get_max(b) != b->tab[b->size - 1])
					rotate(b, 1);
			else
				while (get_max(b) != b->tab[b->size - 1])
					r_rotate(b, 1);
		}
	}
}

void	push_qn(t_list *a, t_list *b, int i)
{
	while (get_min(a) < a->qn[i])
	{
		if (a->tab[a->size - 1] < a->qn[i])
			push(a, b, 1);
		else
			rotate(a, 0);
	}
}

void	sort(t_list *a, t_list *b)
{
	int	i;

	i = -1;
	while (++i != a->size_tab)
		push_qn(a, b, i);
	push_last(a, b);
	sort_b(a, b);
}

void	sort_3(t_list *a)
{
	if (is_sorted(a) == 0)
		return ;
	if (a->tab[0] == get_max(a))
		swap(a, 0);
	else if (a->tab[a->size - 1] == get_max(a))
	{
		rotate(a, 0);
		sort_3(a);
	}
	else
	{
		swap(a, 0);
		sort_3(a);
	}
}

void	sort_5(t_list *a, t_list *b)
{
	while (b->size != 2)
	{
		if (a->tab[a->size - 1] == get_min(a))
		{
			push(a, b, 1);
			continue ;
		}
		else
		{
			if (get_pos_min(a) >= a->size / 2)
				while (get_min(a) != a->tab[a->size - 1])
					rotate(a, 0);
			else
				while (get_min(a) != a->tab[a->size - 1])
					r_rotate(a, 0);
		}
	}
	sort_3(a);
	while (b->size != 0)
		push(b, a, 0);
	exit(0);
}
