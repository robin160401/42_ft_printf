/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:38:00 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/15 12:08:30 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (*string != '\0')
	{
		string++;
		i++;
	}
	return (i);
}

// int main(){
//     char string[] = "Hello World";
//     int i = ft_strlen(string);
//     printf("%d", i);
// }