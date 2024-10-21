/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:38:59 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/21 13:11:08 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsignednbr_fd(int n, int fd)
{
	unsigned int	num;
	int				count;
	int				check_error;

	count = 0;
	check_error = 0;
	num = (unsigned int) n;
	if (num >= 10)
	{
		check_error = ft_putnbr_fd(num / 10, fd);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	check_error = ft_putchar_fd((num % 10) + '0', fd);
	if (check_error == -1)
		return (-1);
	count += check_error;
	return (count);
}
