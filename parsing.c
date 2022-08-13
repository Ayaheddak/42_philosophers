/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 05:01:06 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/13 07:55:11 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(void)
{
	printf("Error\n");
	exit(1);
}
int ft_strlen(char *s) {
	int i = 0;
	if (s)
		while(s[i] != '\0')
		 i++;
	return i;
}
int	atoi_handle(char *av)
{
	int		c;
	int		res;
	int		cmp;

	c = 0;
	res = 0;
	cmp = 1;
	int length = ft_strlen(av);
	while ((av[c] >= '\t' && av[c] <= '\r') || av[c] == ' ')
		c++;
	cmp = -1 * (av[c] == '-') + 1 * (av[c] != '-');
	c += ((av[c] == '-' || av[c] == '+') && av[c + 1]);
	while (av[c] >= '0' && av[c] <= '9')
	{
		res = (av[c] - '0') + (res * 10);
		c++;
	}
	if (cmp == -1 || c != length){	
		return (ft_error());
	}
	return (res);
}
void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	while(1)
	{
		//eat
		//sleep/
		//think
	}
}



void init_philos(t_data *data)
{
	int i;


	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	data->philos = malloc(sizeof(t_philo) * data->nb_of_philo):
	while(i < data->nb_of_philo)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		data->philos[i].id = i + 1;
		data->philos[i].fork_left = i;
		data->philos[i].fork_right = (i + 1) % data->nb_of_philo;
		i++;
	}
}

int main(int ac, char *av[])
{
	t_data		data;
	int			i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	data.nb_of_philo = atoi_handle(av[1]);
	
	data.tab_philos = malloc(sizeof(pthread_t) *( data.nb_of_philo + 1));
	while (i < data.nb_of_philo)
	{
		if (pthread_create(&(data.tab_philos[i]), NULL, &routine, data->philos[i]) != 0)
		{
			return(1);
		}
		i++;
	}
	i = 0;
	while (i < data.nb_of_philo)
	{
		if (pthread_join(data.tab_philos[i], NULL) != 0)
		{
			return (2);
		}
		printf("thread %d has finished execution \n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
}