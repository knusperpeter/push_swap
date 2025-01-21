/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:53:35 by codespace         #+#    #+#             */
/*   Updated: 2023/09/24 18:53:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignednbr(unsigned int n)
{
	char	digit;
	int		chars;

	chars = 0;
	if (n >= 10)
		chars += ft_unsignednbr(n / 10);
	digit = '0' + (n % 10);
	chars += write (1, &digit, 1);
	return (chars);
}

int	ft_putnbrptr(unsigned long int nbr)
{
	int					result;
	int					chars;
	char				*base;

	chars = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		chars += ft_putnbrptr(nbr / 16);
	result = base[nbr % 16];
	chars += write (1, &result, 1);
	return (chars);
}
