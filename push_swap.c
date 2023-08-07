/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:21:17 by nferre            #+#    #+#             */
/*   Updated: 2021/11/18 13:13:29 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*init(int size, int *tab, int ver)
{
	int		i;
	t_list	*temp;

	i = -1;
	temp = malloc(sizeof(t_list));
	if (!(temp))
		return (NULL);
	temp->size = size;
	temp->tab = malloc(sizeof(int) * size);
	if (!(temp))
		return (NULL);
	if (ver == 1)
	{
		while (++i != size)
			temp->tab[i] = 0;
		temp->size = 0;
		return (temp);
	}
	while (++i != size)
		temp->tab[i] = tab[i];
	temp->size = size;
	return (temp);
}

int	check_prev(int *tab, int i, int nb)
{
	int	j;

	j = -1;
	if (tab[0] == nb && i != 0)
	{
		free(tab);
		write(1, "Error\n", 6);
		exit(0);
	}
	while (++j < i)
	{
		if (nb == tab[j])
		{
			free(tab);
			write(1, "Error\n", 6);
			exit(0);
		}
	}
	return (0);
}

int	*get_tab(char **argv, int *tab, int *j)
{
	char	**tab_char;
	int		i;
	int		size;

	i = 0;
	tab_char = ft_split(argv[1], ' ');
	while (tab_char[i])
		i++;
	size = i;
	tab = malloc(sizeof(int) * i);
	i = -1;
	while (++i != size)
	{
		check_prev(tab, i, ft_atoi(tab_char[size - i - 1]));
		tab[i] = ft_atoi(tab_char[size - i - 1]);
		free(tab_char[size - i - 1]);
	}
	free(tab_char);
	*j = size;
	return (tab);
}

int	*get_tab2(int argc, char **argv, int *i)
{
	int	*tab;

	tab = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		if (verify_char(argv) == -1)
			exit(0);
		tab = get_tab(argv, tab, i);
	}
	else
	{
		if (verify_params(argc, argv) != 0)
			exit (0);
		tab = malloc((argc - 1) * sizeof(int));
		*i = 0;
		while (--argc >= 1)
		{
			check_prev(tab, *i, ft_atoi(argv[argc]));
			tab[*i] = ft_atoi(argv[argc]);
			*i += 1;
		}
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	int		*tab;
	int		i;
	t_list	*a;
	t_list	*b;

	i = 0;
	check_if_empty(argc, argv);
	tab = (get_tab2(argc, argv, &i));
	a = init(i, tab, 0);
	b = init(i, tab, 1);
	if (is_sorted(a) == 0)
		return (0);
	if (i == 3)
	{
		sort_3(a);
		return (0);
	}
	else if (i == 5)
		sort_5(a, b);
	if (i > 450)
		find_median500(tab, i, a);
	else
		find_median(tab, i, a);
	sort(a, b);
	free(tab);
}
