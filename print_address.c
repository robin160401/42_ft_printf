/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:54:08 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/21 15:23:12 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_address(unsigned long x)
{
	int		count;
	char	*hexadecimal;
	int		check_error;

	count = 0;
	check_error = 0;
	hexadecimal = "0123456789abcdef";
	if (x < 16)
		return (ft_putchar_fd(hexadecimal[x], 1));
	else
	{
		count = print_address(x / 16);
		if (count == -1)
			return (-1);
		check_error = print_address(x % 16);
		if (check_error == -1)
			return (-1);
		count += check_error;
		return (count);
	}
}
