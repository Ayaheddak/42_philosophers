/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 05:00:31 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/28 17:45:21 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->count = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	data->philos = malloc(sizeof(t_philo) * data->nb_of_philo);
	pthread_mutex_init(&(data->print), NULL);
	while (i < data->nb_of_philo)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		pthread_mutex_init(&(data->philos[i].is_eating), NULL);
		pthread_mutex_init(&(data->philos[i].tm_last_meals), NULL);
		pthread_mutex_init(&(data->philos[i].count_meals), NULL);
		data->philos[i].id = i + 1;
		data->philos[i].fork_left = i;
		data->philos[i].fork_right = (i + 1) % data->nb_of_philo;
		data->philos[i].data = data;
		data->philos[i].last_meal = get_time();
		data->philos[i].meals_count = 0;
		data->philos[i].lock = 0;
		data->philos[i].iseating = 0;
		i++;
	}
}

void	init_args(int ac, char *av[], t_data *data)
{
	data->nb_of_philo = atoi_handle(av[1]);
	data->tm_to_die = atoi_handle(av[2]);
	data->tm_to_eat = atoi_handle(av[3]);
	data->tm_to_sleep = atoi_handle(av[4]);
	if (ac == 6)
		data->nb_of_ms_eat = atoi_handle(av[5]);
	else
		data->nb_of_ms_eat = -1;
}

int	main_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_mutex_lock(&data->philos[i].tm_last_meals);
		if ((int)get_time() - data->philos[i].last_meal >= data->tm_to_die)
		{
			print_to_screen(" has died ", &data->philos[i]);
			return (1);
		}
		pthread_mutex_unlock(&data->philos[i].tm_last_meals);
		pthread_mutex_lock(&data->philos[i].count_meals);
		if (data->nb_of_ms_eat > 0 && data->philos[i].meals_count >= data->nb_of_ms_eat && data->philos[i].lock == 0 )
		{
			data->count++;
			data->philos[i].lock = 1;
		}
		pthread_mutex_unlock(&data->philos[i].count_meals);
		if ( data->count == data->nb_of_philo)
			pthread_mutex_lock(&data->philos[i].is_eating);
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_data		*data;
	int			i;

	i = 0;
	data = malloc(sizeof(t_data));
	if (ac == 5 || ac == 6)
	{
		init_args(ac, av, data);
		init_philos(data);
		data->start = get_time();
		while (i < data->nb_of_philo)
		{
			pthread_create(&(data->philos[i].th), NULL,
				(void *)routine, (&(data->philos[i])));
			i++;
		}
	}
	while (1)
	{
		if ( main_thread(data) == 1 || data->count == data->nb_of_philo)
			break;
	}system("leaks philo");
	return (0);
}
/* -fsanitize=thread */