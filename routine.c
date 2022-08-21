/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 05:30:34 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/21 16:21:51 by aheddak          ###   ########.fr       */
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
	timer(philo->data->tm_to_eat);
	philo->last_meal = get_time();
	philo->meals_count++;
	printf("meals count ----> %d philo ---> %d \n", philo->meals_count, philo->id);
	// if (philo->meals_count >= philo->data->nb_of_ms_eat)
	// {
	// 	print_to_screen(" has died ", philo);
	// 	exit(1);
	// }
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
	int i;

	i = 0;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
