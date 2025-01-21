/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:27:43 by chris             #+#    #+#             */
/*   Updated: 2023/12/08 18:18:06 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ismin(t_list *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = stack->content;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->content < i)
			i = stack->content;
	}
	return (i);
}

int	ismax(t_list *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = stack->content;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->content > i)
			i = stack->content;
	}
	return (i);
}

void	sortthree(t_list **stack)
{
	if ((*stack)->content == ismin(*stack) && !is_sorted(*stack))
	{
		sa(stack);
		ra(stack);
	}
	else if ((*stack)->content == ismax(*stack) && !is_sorted(*stack))
	{
		if ((*stack)->next->content == ismin(*stack))
			ra(stack);
		else
		{
			sa(stack);
			rra(stack);
		}
	}
	else if (!is_sorted(*stack))
	{
		if ((*stack)->next->content == ismin(*stack))
			sa(stack);
		else
			rra(stack);
	}
}

void	sortfour(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->content == ismin(*stack_a) && !is_sorted(*stack_a))
	{
		pb(stack_a, stack_b);
		sortthree(stack_a);
	}
	else if ((*stack_a)->next->content == ismin(*stack_a)
		&& !is_sorted(*stack_a))
	{
		sa(stack_a);
		pb(stack_a, stack_b);
		sortthree(stack_a);
	}
	else if (ft_lstlast(*stack_a)->content == ismin(*stack_a)
		&& !is_sorted(*stack_a))
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		sortthree(stack_a);
	}
	else if (!is_sorted(*stack_a))
		helper(stack_a, stack_b);
	pa(stack_a, stack_b);
}
