/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:14:25 by caigner           #+#    #+#             */
/*   Updated: 2024/03/09 14:06:26 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	checkforonearg(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && str[1])
		i++;
	if ((str[i] == '0' && ft_isdigit(str[i + 1]))
		|| (str[0] == '-' && str[1] == '0'))
		terminate(NULL, 0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			terminate(NULL, 0);
		i++;
	}
}

void	prepareargv(char **av, int ac, t_args *args)
{
	if (av[1][0] == '0' && av[1][1])
		terminate(args, 0);
	if (ac == 1 || ((ac == 2) && av[1][0] == 0))
	{
		terminate(NULL, 0);
	}
	else if (ac == 2)
	{
		args->alocated = 1;
		if (!ft_strchr(av[1], ' ' ))
		{
			checkforonearg(av[1]);
			exit(0);
		}
		args->args = ft_split(av[1], ' ');
		if (!args->args)
			terminate(NULL, 0);
		inputcheck(args);
	}
	else
	{
		args->alocated = 0;
		args->args = av + 1;
		inputcheck(args);
	}
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	initstructs(t_list **stack_a, t_list **stack_b, t_args *args)
{
	*stack_a = NULL;
	*stack_b = NULL;
	args->args = NULL;
	args->alocated = 0;
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_args	args;

	if (ac <= 1)
		return (0);
	initstructs(&stack_a, &stack_b, &args);
	prepareargv(av, ac, &args);
	parse(&args, &stack_a);
	if (args.alocated)
		freearray(args.args);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
