/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:14:43 by caigner           #+#    #+#             */
/*   Updated: 2023/12/08 19:17:36 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_args
{
	char	**args;
	int		alocated;
}	t_args;

void	terminate(t_args *args, int status);
void	cleanup(t_list *start, t_list *newtemp, t_list *last);
void	free_stack(t_list **stack);
void	freearray(char **arr);
void	parse(t_args *args, t_list **stack_a);
void	longsort(t_list **stack_a, t_list **stack_b);
void	sortfive(t_list **stack_a, t_list **stack_b);
void	sort_swap(t_list *a, t_list *b);
void	bubblesort(t_list **start);
void	replacewithindex(t_list *original, t_list *sorted);
void	helper(t_list **stack_a, t_list **stack_b);
void	sortthree(t_list **stack);
void	sort(t_list **stack_a, t_list **stack_b);
void	sortthree(t_list **stack);
void	sortfour(t_list **stack_a, t_list **stack_b);
int		maxmincheck(t_args *args, char *input);
int		rotate(t_list **list);
int		inputcheck(t_args *args);
int		rrotate(t_list **list);
int		push(t_list **old, t_list **new);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
int		findindex(t_list *start, int num);
int		swap(t_list **lst1);
int		ismin(t_list *stack);
int		ismax(t_list *stack);
int		is_sorted(t_list *stack);
t_list	*copylist(t_list *start);

#endif