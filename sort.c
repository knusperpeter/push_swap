/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:21:34 by caigner           #+#    #+#             */
/*   Updated: 2023/12/08 19:08:29 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include "libft/libft.h"

t_list	*copylist(t_list *start)
{
	t_list	*temp;
	t_list	*newstart;
	t_list	*newtemp;
	t_list	*last_successful;

	temp = start;
	newstart = ft_lstnew(temp->content);
	if (!newstart)
	{
		free_stack(&start);
		terminate(NULL, 1);
	}
	newtemp = newstart;
	last_successful = newtemp;
	temp = temp->next;
	while (temp)
	{
		newtemp->next = ft_lstnew(temp->content);
		cleanup(start, newtemp, last_successful);
		newtemp = newtemp->next;
		temp = temp->next;
	}
	return (newstart);
}

void	radix(int max_num, int max_bits, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= max_num)
		{
			if (*stack_a == NULL)
				break ;
			num = (*stack_a)->content;
			if (((num >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}

void	longsort(t_list **stack_a, t_list **stack_b)
{
	int	max_num;
	int	max_bits;

	max_num = ft_lstsize(*stack_a) - 1;
	max_bits = 0;
	while (max_num >> max_bits != 0)
		++max_bits;
	radix(max_num, max_bits, stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (is_sorted(*stack_a) || size < 2)
		return ;
	else if (size == 5)
		sortfive(stack_a, stack_b);
	else if (size == 4)
		sortfour(stack_a, stack_b);
	else if (size == 3)
		sortthree(stack_a);
	else if (size == 2)
		sa(stack_a);
	else
	{
		*stack_b = copylist(*stack_a);
		bubblesort(stack_b);
		replacewithindex(*stack_a, *stack_b);
		free_stack(stack_b);
		*stack_b = NULL;
		longsort(stack_a, stack_b);
	}
}
