/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:19:11 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 16:19:11 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	q_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *a, int first, int last)
{
	int	pivot;
	int	i;
	int	j;

	pivot = a[last];
	i = first;
	j = i;
	while (j < last)
	{
		if (a[j] < pivot)
		{
			q_swap(&a[i], &a[j]);
			i++;
		}
		j++;
	}
	q_swap(&a[i], &a[last]);
	return (i);
}

// sort the list (sorted list will be used as base for logic)
void	q_sort(int *a, int first, int last)
{
	int	mid;

	if (first < last)
	{
		mid = partition(a, first, last);
		q_sort(a, first, (mid - 1));
		q_sort(a, (mid + 1), last);
	}
}

// duplicates the list
int	*int_dup(int *a, int size_a)
{
	int	*dup;
	int	i;

	dup = (int *) malloc (sizeof(int) * size_a);
	i = -1;
	while (++i < size_a)
		dup[i] = a[i];
	return (dup);
}
