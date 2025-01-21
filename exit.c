/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:19:08 by caigner           #+#    #+#             */
/*   Updated: 2023/12/12 16:03:15 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	cleanup(t_list *start, t_list *newtemp, t_list *last)
{
	if (!newtemp->next)
	{
		free_stack(&last);
		if (start != NULL)
		{
			free_stack(&start);
			terminate(NULL, 1);
		}
	}
}

void	terminate(t_args *args, int status)
{
	int	i;

	i = 0;
	if (args && args->alocated)
	{
		while (args->args[i])
		{
			free(args->args[i++]);
		}
		free(args->args);
	}
	write (2, "Error\n", 6);
	//ft_printf("Error\n");
	exit(status);
}

void	freearray(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i++]);
		}
		free(arr);
	}
}
