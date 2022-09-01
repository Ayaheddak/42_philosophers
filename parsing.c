/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 05:01:06 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/31 01:21:29 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			i++;
	return (i);
}

int	atoi_handle(char *av)
{
	int		c;
	int		res;
	int		length;

	c = 0;
	res = 0;
	length = ft_strlen(av);
	while ((av[c] >= '\t' && av[c] <= '\r') || av[c] == ' ')
		c++;
	c += ((av[c] == '+') && av[c + 1]);
	if (av[c] >= '0' && av[c] <= '9')
	{
		while (av[c] >= '0' && av[c] <= '9')
		{
			res = (av[c] - '0') + (res * 10);
			c++;
		}
	}
	if (c != length)
		return (-1);
	return (res);
}
