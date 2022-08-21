/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 05:01:06 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/21 15:14:33 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*-------------------routine-----------------------*/
void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->fork_left]);
	print_to_screen(" has taken left fork ", philo);
	pthread_mutex_lock(&philo->data->forks[philo->fork_right]);
	print_to_screen(" has taken right fork ", philo);
	print_to_screen(" is eating ", philo); 
	timer(philo->data->tm_to_eat );
	philo->last_meal = get_time();
	philo->meals_count++;
	pthread_mutex_unlock(&philo->data->forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->data->forks[philo->fork_right]);
}

void	philo_think(t_philo *philo)
{
	print_to_screen(" is thinking ", philo);
}

void	philo_sleep(t_philo *philo)
{
	timer(philo->data->tm_to_sleep);
	print_to_screen(" is sleeping ", philo);

}
void	*routine(t_philo	*philo)
{
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

/*---------------------initialization------------------------*/
void init_philos(t_data *data)
{
	int i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	data->philos = malloc(sizeof(t_philo) * data->nb_of_philo);
	while(i < data->nb_of_philo)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		data->philos[i].id = i + 1;
		data->philos[i].fork_left = i;
		data->philos[i].fork_right = (i + 1) % data->nb_of_philo;
		data->philos[i].data = data;	
		i++;
	}
}

int main(int ac, char *av[])
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
	while(1)//main loop
	{
		i = 0;
		while(i < data.nb_of_philo)
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