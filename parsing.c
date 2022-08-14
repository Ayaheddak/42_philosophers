/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 05:01:06 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/14 06:09:46 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


/*-------------------routine-----------------------*/
// void *routine(void *arg)
// {
// 	//t_philo *philo;
// 	//philo = (t_philo *) arg;
// 	while(1)
// 	{
// 		//printf(philos id kayeml chi haja);
// 		//usleep(1000);
// 		//eat
// 		//sleep
// 		//think
// 	}
// }

// void print_to_screen(int i, char *s)
// {
// }
void	philo_eat(t_data *data)
{
	pthread_mutex_lock(&data->forks[data->philos->fork_left]);
	printf("philo ---> %d taken left fork %d  \n",data->philos->id,data->philos->fork_left);
	pthread_mutex_lock(&data->forks[data->philos->fork_right]);
	printf("philo ---> %d taken right fork %d  \n",data->philos->id,data->philos->fork_right );
	printf("philo ---> %d is eating \n",data->philos->id);
	sleep(5);
	pthread_mutex_unlock(&data->forks[data->philos->fork_left]);
	pthread_mutex_unlock(&data->forks[data->philos->fork_right]);
}
void	*routine(t_data *data)
{
	while (1)
	{
		philo_eat(data);
	}
}
void	philo_thing(t_philo *philo)
{
	
}

void	philo_sleep(t_philo *philo)
{
	
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
		// printf("id of philo ---->%d\n", data->philos[i].id );
		data->philos[i].fork_left = i;
		// printf("nb left fork ---->%d\n", data->philos[i].fork_left );
		data->philos[i].fork_right = (i + 1) % data->nb_of_philo;
		// printf("nb right fork ---->%d\n", data->philos[i].fork_right);	
		i++;
	}
}

int main(int ac, char *av[])
{
	t_data		data;
	int			i;

	i = 0;
	if (ac == 2)
	{
		data.nb_of_philo = atoi_handle(av[1]);
		init_philos(&data);
		routine(&data);
	}
	// pthread_mutex_init(&mutex, NULL);
	// data.tab_philos = malloc(sizeof(pthread_t) *( data.nb_of_philo + 1));
	// while (i < data.nb_of_philo)
	// {
	// if (pthread_create(&(data.tab_philos[i]), NULL, &routine, data->philos[i]) != 0)
	//  	{
	//  		return(1);
	//  	}
	//  	i++;
	// }
	// i = 0;
	// while (i < data.nb_of_philo)
	// {
	// 	if (pthread_join(data.tab_philos[i], NULL) != 0)
	// 	{
	// 		return (2);
	// 	}
	// 	printf("thread %d has finished execution \n", i);
	// 	i++;
	// }
	// pthread_mutex_destroy(&mutex);
}