/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:13:30 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/20 13:05:41 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
# include <stdarg.h>

// static	int	count_format_specifiers(char *format)
// {
// 	int		count;

// 	count = 0;
// 	while (format[count])
// 		if (format[count] == '%' && format[count + 1] != '%')
// 			count ++;
// 	return (count);
// }

static	int	print_different_formats(char *s, va_list ap)
{
	if (*s == '%')
		return (ft_putchar_fd('%', 1));
	else if (*s == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (*s == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	else if (*s == 'd')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (*s == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	return (1);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		count_output;

	count_output = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count_output += print_different_formats(format, ap);
			format++;
		}
		count_output += ft_putchar_fd(*format, 1);
		format++;
	}
	return (count_output);
}

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s\n", "John");
	ft_printf("The chars written are %d\n", count);
}