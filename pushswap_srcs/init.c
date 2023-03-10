/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:19:01 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 16:19:01 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_chunk(t_pushswap *stack)
{
	if (stack->stack_b[0] < stack->stack_b[1])
		sb(stack);
	pa(stack);
	pa(stack);
	ra(stack);
	return (0);
}

void	init_stacks(t_pushswap *stack)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
	stack->stack_a = int_dup(stack->un_sorted, stack->total_size);
	stack->a_size = stack->total_size;
	stack->stack_b = malloc (sizeof(int) * stack->total_size);
	stack->b_size = 0;
}

void	init_struct(t_pushswap *pushswap)
{
	pushswap->stack_a = NULL;
	pushswap->stack_b = NULL;
	pushswap->sorted = NULL;
	pushswap->un_sorted = NULL;
	pushswap->total_size = 0;
	pushswap->a_size = 0;
	pushswap->b_size = 0;
}
