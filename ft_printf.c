/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:13:30 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/20 15:02:25 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

// static	int	count_format_specifiers(char *format)
// {
// 	int		count;

// 	count = 0;
// 	while (format[count])
// 		if (format[count] == '%' && format[count + 1] != '%')
// 			count ++;
// 	return (count);
// }

static	int	print_hexadecimal(char lower_or_upper, unsigned int x)
{
	int		count;
	char	*hexadecimal;
	int		charswritten;

	if (lower_or_upper == 'x')
		hexadecimal = "0123456789abcdef";
	else
		hexadecimal = "0123456789ABCDEF";
	if (x < 16)
		return (ft_putchar_fd(hexadecimal[x], 1));
	else
	{
		count = print_hexadecimal(lower_or_upper, x / 16);
		count += print_hexadecimal(lower_or_upper, x % 16);
		return (count);
	}
}

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
	else if (*s == 'u')
		return (ft_putunsignednbr_fd(va_arg(ap, int), 1));
	else if (*s == 'x')
		return (print_hexadecimal('x', va_arg(ap, unsigned int)));
	else if (*s == 'X')
		return (print_hexadecimal('X', va_arg(ap, unsigned int)));
	// else if (*s == 'p')
	// 	return (print_hexadecimal(va_arg(ap, unsigned int)));
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
	va_end(ap);
	return (count_output);
}

int	main(void)
{
	int	count;
	int count2;
	int hexa = -12;
	count2 = 20;


	count = ft_printf("The chars written are, in hexadecima %d, %x\n", count2, hexa);
	ft_printf("%d\n", count);
	count = printf("The chars written are, in hexadecima %d, %x\n", count2, hexa);
	printf("%d\n", count);
}