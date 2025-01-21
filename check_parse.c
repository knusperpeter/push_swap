/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:17:07 by caigner           #+#    #+#             */
/*   Updated: 2023/12/11 17:52:41 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <stddef.h>
#include <stdlib.h>

int	maxmincheck(t_args *args, char *input)
{
	int		n;
	char	*a;

	n = ft_atoi(input);
	a = ft_itoa(n);
	if (!a)
		terminate(args, 1);
	if (ft_strncmp(input, a, ft_strlen(input)) != 0)
	{
		free(a);
		terminate(NULL, 0);
	}
	free(a);
	return (1);
}

void	doublecheck(t_args *args)
{
	int	i;
	int	j;

	i = 0;
	while (args->args[i])
	{
		j = i + 1;
		while (args->args[j])
		{
			if (ft_strncmp(args->args[i], args->args[j], 11) == 0)
				terminate(args, 0);
			j++;
		}
		i++;
	}
}

int	inputcheck(t_args *args)
{
	int	i;
	int	j;
	int	quantity;

	quantity = 0;
	j = 0;
	while (args->args[j])
	{
		i = 0;
		while (args->args[j][i])
		{
			if ((!ft_isdigit(args->args[j][i]) && args->args[j][i] != '-') ||
				(args->args[j][i] == '-'
				&& (i + 1 < (int)ft_strlen(args->args[j]))
				&& !ft_isdigit(args->args[j][i + 1])))
				terminate(args, 0);
			i++;
		}
		quantity += maxmincheck(args, args->args[j]);
		j++;
	}
	doublecheck(args);
	return (quantity);
}

void	parse(t_args *args, t_list **stack_a)
{
	t_list	*curr;
	int		content;
	int		i;

	i = 0;
	curr = NULL;
	while (args->args[i])
	{
		if (args->args[i][0] == 0)
		{
			free_stack(stack_a);
			terminate(args, 0);
		}
		content = ft_atoi(args->args[i]);
		curr = ft_lstnew(content);
		if (!curr)
		{
			if (*stack_a != NULL)
				free_stack(stack_a);
			terminate(args, 1);
		}
		ft_lstadd_back(&(*stack_a), curr);
		i++;
	}
}

void	replacewithindex(t_list *original, t_list *sorted)
{
	t_list	*temp;
	int		index;

	temp = original;
	while (temp != NULL)
	{
		index = findindex(sorted, temp->content);
		if (index != -1)
			temp->content = index;
		else
			break ;
		temp = temp->next;
	}
}
