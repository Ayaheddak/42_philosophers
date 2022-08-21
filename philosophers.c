/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 05:00:31 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/21 15:40:35 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*---------------------initialization------------------------*/
void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	data->philos = malloc(sizeof(t_philo) * data->nb_of_philo);
	while (i < data->nb_of_philo)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		data->philos[i].id = i + 1;
		data->philos[i].fork_left = i;
		data->philos[i].fork_right = (i + 1) % data->nb_of_philo;
		data->philos[i].data = data;
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_data		data;
	int			i;

	i = 0;
	if (ac > 1)
	{
		data.nb_of_philo = atoi_handle(av[1]);
		data.tm_to_die = atoi_handle(av[2]);
		data.tm_to_eat = atoi_handle(av[3]);
		data.tm_to_sleep = atoi_handle(av[4]);
		init_philos(&data);
		data.start = get_time();
		while (i < data.nb_of_philo)
		{
			pthread_create(&(data.philos[i].th), NULL, (void *)routine, &data.philos[i]);
			i++;
		}		
	}
	timer(500);
	while (1)//main loop
	{
		i = 0;
		while (i < data.nb_of_philo)
		{
			if (get_time() - data.philos[i].last_meal > data.tm_to_die)
			{
				print_to_screen(" has died ", &data.philos[i]);
				exit(0);
			}
			i++;
		}
	}
}
