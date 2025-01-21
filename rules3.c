/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:32:00 by chris             #+#    #+#             */
/*   Updated: 2023/12/05 09:32:24 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	return (0);
}

int	rrotate(t_list **list)
{
	int		size;
	t_list	*last;
	t_list	*tmp;

	if (!list || !(*list) || !(*list)->next)
		return (-1);
	tmp = *list;
	size = ft_lstsize(*list) - 1;
	last = ft_lstlast(*list);
	while (size-- > 1)
		tmp = tmp->next;
	ft_lstadd_front(list, last);
	tmp->next = NULL;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (rrotate(stack_a) == -1)
		return (-1);
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (rrotate(stack_b) == -1)
		return (-1);
	ft_printf("rrb\n");
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
	return (0);
}
