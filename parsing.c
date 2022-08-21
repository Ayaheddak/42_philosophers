/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 05:01:06 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/21 15:42:17 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(void)
{
	printf("Error\n");
	exit(1);//roooood lbaaaal forbidden
}

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
	int		cmp;
	int		length;

	c = 0;
	res = 0;
	cmp = 1;
	length = ft_strlen(av);
	while ((av[c] >= '\t' && av[c] <= '\r') || av[c] == ' ')
		c++;
	cmp = -1 * (av[c] == '-') + 1 * (av[c] != '-');
	c += ((av[c] == '-' || av[c] == '+') && av[c + 1]);
	while (av[c] >= '0' && av[c] <= '9')
	{
		res = (av[c] - '0') + (res * 10);
		c++;
	}
	if (cmp == -1 || c != length)
		return (ft_error());
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
