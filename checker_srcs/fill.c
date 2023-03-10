/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:04:45 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 17:26:20 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	realloc_tab(t_pushswap *stack, int new_size, char **new_stuff)
{
	int	*new;
	int	i;
	int	j;

	i = 0;
	new = malloc (sizeof(int) * new_size);
	if (stack->stack_a)
	{
		while (i < stack->total_size)
		{
			new[i] = stack->stack_a[i];
			++i;
		}
	}
	j = 0;
	while (new_stuff[j])
	{
		new[i] = ft_atoi(new_stuff[j], stack, new_stuff, new);
		++i;
		++j;
	}
	if (stack->stack_a)
		free(stack->stack_a);
	stack->stack_a = new;
	stack->total_size = new_size;
}

unsigned int	count_elem(char **stuff)
{
	unsigned int	i;

	i = 0;
	while (stuff[i])
		++i;
	return (i);
}

int	fill(t_pushswap *stack, char **av, int ac)
{
	char	**temp;
	int		i;

	i = 1;
	while (i < ac)
	{
		temp = ft_split(av[i], ' ');
		realloc_tab(stack, (count_elem(temp) + stack->total_size), temp);
		freedoublechar(temp);
		++i;
	}
	return (1);
}
