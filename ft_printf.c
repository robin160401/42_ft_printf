/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:13:30 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/19 17:59:43 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static	int	count_format_specifiers(const char *format)
{
	int		count;

	count = 0;
	while (format[count])
		if (format[count] == "%" && format[count + 1] != "%")
			count ++;
	return (count);
}

static	int	print_different_formats(const char *s)
{
	if (*s == "")
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		format_specifiers;
	int		count_arguments;

	format_specifiers = 0;
	format_specifiers = count_format_specifiers(format);
	va_start(ap, format_specifiers);
	while (*format)
	{
		if (*format == "%")
		{
			format++;
			
		}
	}

	return ();
}

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s\n", "John");
	ft_printf("The chars written are %d\n", count);
}