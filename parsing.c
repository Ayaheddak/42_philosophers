/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 05:01:06 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/16 03:30:05 by aheddak          ###   ########.fr       */
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

// void print_to_screen()
// {
// }
void	philo_eat(t_philo *philo)
{

	pthread_mutex_lock(&philo->data->forks[philo->fork_left]);
	//pthread_mutex_lock(&philo->data->print);
	printf("philo ---> %d taken left fork %d  \n",philo->id, philo->fork_left);
	//pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_lock(&philo->data->forks[philo->fork_right]);
	//pthread_mutex_lock(&philo->data->print);
	printf("philo ---> %d taken right fork %d  \n",philo->id, philo->fork_right);
	//pthread_mutex_unlock(&philo->data->print);
		printf("philo ---> %d is eating \n",philo->id);
		//akir mara cla = get time now;
	//this philo meal count++
	//if (this philo meal count == info->meal count )
		//philo shba3++
	usleep(1000);
	pthread_mutex_unlock(&philo->data->forks[philo->fork_left]);
// printf("philo ---> %d unlocked left fork %d  \n",philo->id, philo->fork_left);
	pthread_mutex_unlock(&philo->data->forks[philo->fork_right]);
// printf("philo ---> %d unlocked right fork %d  \n",philo->id, philo->fork_right);
}

void	*routine(t_philo	*philo)
{
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		philo_eat(philo);
		//philo sleep usleep(1000);
		//philo think
		
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
		data->philos[i].data = data;
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
		// data.tm_to_die = atoi_handle(av[2]);
		// data.tm_to_eat =atoi_handle(av[3]);
		// data.nb_of_ms_eat=atoi_handle(av[4]);
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