/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 05:00:31 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/21 18:24:19 by aheddak          ###   ########.fr       */
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
		data->philos[i].last_meal = get_time();
		data->philos[i].meals_count = 0;
		data->philos[i].lock = 0;
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_data		data;
	int			count;
	int			i;

	count  = 0;

	i = 0;
	if (ac > 1)
	{
		data.nb_of_philo = atoi_handle(av[1]);
		data.tm_to_die = atoi_handle(av[2]);
		data.tm_to_eat = atoi_handle(av[3]);
		data.tm_to_sleep = atoi_handle(av[4]);
		if (ac == 6)
			data.nb_of_ms_eat = atoi_handle(av[5]);
		else
			data.nb_of_ms_eat = -1;
		init_philos(&data);
		data.start = get_time();
		while (i < data.nb_of_philo)
		{
			pthread_create(&(data.philos[i].th), NULL, (void *)routine, &data.philos[i]);
			i++;
		}	
	}
	while (1)//main loop
	{
		i = 0;
		while (i < data.nb_of_philo)
		{
			if (get_time() - data.philos[i].last_meal >= data.tm_to_die)
			{
				print_to_screen(" has died ", &data.philos[i]);
				exit(0);
			}
			if (data.nb_of_ms_eat >= 0 && data.philos[i].meals_count >= data.nb_of_ms_eat && data.philos[i].lock == 0)
			{
				count++;
				data.philos[i].lock = 1;
			}
			i++;
		}
		if (count == data.nb_of_philo)
		{
				exit(0);
		}
	}
}
