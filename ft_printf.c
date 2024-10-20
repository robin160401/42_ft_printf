/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:13:30 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/20 19:55:27 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static	int	print_hexadecimal(int islower, unsigned long x)
{
	int		count;
	char	*hexadecimal;

	if (islower)
		hexadecimal = "0123456789abcdef";
	else
		hexadecimal = "0123456789ABCDEF";
	if (x < 16)
		return (ft_putchar_fd(hexadecimal[x], 1));
	else
	{
		count = print_hexadecimal(islower, x / 16);
		count += print_hexadecimal(islower, x % 16);
		return (count);
	}
}

static	int	print_different_formats(const char *s, va_list ap)
{
	if (*s == 'c')
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
		return (print_hexadecimal(1, va_arg(ap, unsigned int)));
	else if (*s == 'X')
		return (print_hexadecimal(0, va_arg(ap, unsigned int)));
	else if (*s == 'p')
		return (write(1, "0x", 2)
			+ print_hexadecimal(1, va_arg(ap, unsigned long)));
	return (ft_putchar_fd('%', 1));
}

int	ft_printf(const char *format, ...)
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
		if (*format != '\0')
		{
			count_output += ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(ap);
	return (count_output);
}

int	main(void)
{
	int	count;
	int count2;
	// int hexa = -12;
	// count2 = 20;

	ft_printf("My printf %i \n", -1111);
	printf("Real printf %i \n", -1111);
	ft_printf("My printf %d \n", -1111);
	printf("Real printf %d \n", -1111);
	count = ft_printf("My printf %%%% \n");
	printf("My count %d \n", count);
	count2 = printf("Real printf %%%% \n");
	printf("Original count %d \n", count2);
}
