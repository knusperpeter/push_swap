/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:31:27 by caigner           #+#    #+#             */
/*   Updated: 2023/12/05 11:17:14 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sortfive(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp && tmp->content != ismin(tmp) && i++ != -1)
		tmp = tmp->next;
	if (i == 1)
		sa(stack_a);
	else if (i == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	while (i >= 3 && i < 5)
	{
		rra(stack_a);
		i++;
	}
	if (!is_sorted(*stack_a))
	{
		pb(stack_a, stack_b);
		sortfour(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	sort_swap(t_list *a, t_list *b)
{
	int	temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void	bubblesort(t_list **start)
{
	int		swapped;
	t_list	*ptr1;
	t_list	*lptr;

	lptr = NULL;
	if (start == NULL || *start == NULL)
		return ;
	while (1)
	{
		swapped = 0;
		ptr1 = *start;
		while (ptr1->next != lptr)
		{
			if (ptr1->content > ptr1->next->content)
			{
				sort_swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
		if (!swapped)
			break ;
	}
}

int	findindex(t_list *start, int num)
{
	int		index;
	t_list	*temp;

	index = 0;
	temp = start;
	while (temp != NULL)
	{
		if (temp->content == num)
			return (index);
		temp = temp->next;
		index++;
	}
	return (-1);
}

void	helper(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	sa(stack_a);
	pb(stack_a, stack_b);
	sortthree(stack_a);
}
