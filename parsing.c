/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 05:01:06 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/18 08:00:40 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*-------------------routine-----------------------*/
void	philo_eat(t_philo *philo)
{
	//printf("time_start ---> %llu \n", philo->time_start );
	//printf("get_time ---> %llu \n",get_time());
	pthread_mutex_lock(&philo->data->forks[philo->fork_left]);
	pthread_mutex_lock(&philo->data->print);
	print_to_screen(" has taken a left fork ", philo);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_lock(&philo->data->forks[philo->fork_right]);
	pthread_mutex_lock(&philo->data->print);
	print_to_screen(" has taken a right fork ", philo);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_lock(&philo->is_eating);
	pthread_mutex_lock(&philo->data->print);
	print_to_screen(" is eating ", philo);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_lock(&philo->is_eating);
	timer(philo->data->tm_to_eat * 1000);
	//pthread_mutex_lock(&philo->data->print);
	//print_to_screen(" has taken a fork ", philo);
	//pthread_mutex_unlock(&philo->data->print);
	//philo->time_start = get_time();
	// print_to_screen("is eating", philo);
	//printf("philo ---> %d taken right fork %d  \n",philo->id, philo->fork_right);
	//akir mara cla = get time now;//
	philo->last_meal= get_time();
	philo->meals_count++;
	//printf("last_meal ---> %lu \n", philo->last_meal);
	//printf("get_time ---> %llu \n",get_time());
	//this philo meal count++
	// if (this philo meal count == info->meal count )
	// 	//philo shba3++
	//usleep(1000);
	pthread_mutex_lock(&philo->is_eating);
	pthread_mutex_unlock(&philo->data->forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->data->forks[philo->fork_right]);
	//pthread_mutex_lock(&philo->data->print);
	// print_to_screen(" is eating", philo);
	// pthread_mutex_unlock(&philo->data->print);
}

void	philo_thing(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	print_to_screen(" is thinking ", philo);
	pthread_mutex_unlock(&philo->data->print);
}

void	philo_sleep(t_philo *philo)
{
	timer(philo->data->tm_to_sleep * 1000);
	pthread_mutex_lock(&philo->data->print);
	print_to_screen(" is sleeping ", philo);
	pthread_mutex_unlock(&philo->data->print);
}
void	*routine(t_philo	*philo)
{
	if (philo->id % 2 == 0)
		timer(philo->data->tm_to_sleep * 1000);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_thing(philo);
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
		//data.tm_to_die = atoi_handle(av[2]);
		data.tm_to_eat =atoi_handle(av[2]);
		//data.nb_of_ms_eat=atoi_handle(av[4]);
		init_philos(&data);
		// routine(&data);
		while (i < data.nb_of_philo)
		{
			pthread_create(&(data.philos[i].th), NULL, (void *)routine, &data.philos[i]);
			usleep(1000);
	 		i++;
		}		
	}
	i = -1;
	// while (++i < data.nb_of_philo)
	// 	pthread_join(data.philos[i].th, NULL);

	while(1)
	{
		int j;

		j = 0;
		while(1)/// loop over philos
		{
			/// if (get time - akkiramara kla > time to die)
			//{
				//mat lphilo
				//exit	
			//}
			//if (shba3 == num of philos)
			//{
				//mat lphilo
				//exit	
			//}
			
		}
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
	//}
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