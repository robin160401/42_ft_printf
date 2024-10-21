/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:34:03 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/19 15:53:37 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstrings(char const *s, char c)
{
	int	counter;
	int	bool;

	bool = 0;
	counter = 0;
	while (*s)
	{
		if (*s == c)
			bool = 0;
		else if (*s != c && !bool)
		{
			counter++;
			bool = 1;
		}
		s++;
	}
	return (counter);
}

static int	ft_free(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (-1);
}

static int	ft_fillarrays(char const *s, char c, int i, char **array)
{
	int			len;
	char const	*start;

	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		start = s;
		len = 0;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		array[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!array[i])
			return (ft_free(array, i));
		ft_strlcpy(array[i], start, len + 1);
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int			strings_number;
	char		**array;
	int			i;

	if (!s)
		return (NULL);
	i = 0;
	strings_number = ft_countstrings(s, c);
	array = (char **)malloc((strings_number + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = ft_fillarrays(s, c, i, array);
	if (i == -1)
		return (NULL);
	array[i] = NULL;
	return (array);
}

// int	main(void)
// {
// 	char	**array;

// 	array = ft_split("pelase1split1my1test11", '1');

// 	printf("%s\n", array[0]);
// 	printf("%s\n", array[1]);
// 	printf("%s\n", array[2]);
// 	printf("%s\n", array[3]);
// 	printf("%s\n", array[4]);
// 	printf("%s\n", array[5]);
// }
