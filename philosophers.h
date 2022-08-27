/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:46:05 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/27 15:32:51 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_philo	t_philo;
typedef struct s_data
{
	int				nb_of_philo;
	int				tm_to_die;
	int				tm_to_eat;
	int				tm_to_sleep;
	int				nb_of_ms_eat;
	int				count;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	uint64_t		start;
}		t_data;

typedef struct s_philo
{
	int				id;
	int				fork_left;
	int				fork_right;
	uint64_t		last_meal;
	uint64_t		meals_count;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	tm_last_meals;
	pthread_mutex_t	count_meals;
	pthread_t		th;
	int				lock;
	t_data			*data;
}		t_philo;
int			atoi_handle(char *av);
void		print_to_screen(char *string, t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		*routine(t_philo *philo);
void		timer(int time);
uint64_t	get_time(void);
void		print_to_screen(char *string, t_philo *philo);
#endif
