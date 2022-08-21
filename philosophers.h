/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:46:05 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/21 15:45:05 by aheddak          ###   ########.fr       */
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
	int				nb_of_ms_eat;//+ arg 5
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;//
	int				shba3;//
	uint64_t		start;
}		t_data;

typedef struct s_philo
{
	int				id;
	int				fork_left;
	int				fork_right;
	uint64_t 	last_meal;
	unsigned int 	meals_count;
	pthread_mutex_t	is_eating;
	pthread_t		th;
	t_data			*data;
}		t_philo;
/*
// The tv argument is a struct timeval (as specified in <sys/time.h>):
struct timeval 
{
    time_t      tv_sec;     // used for seconds 
//tv_sec the number of seconds elapsed(passe) since like 21/1/2001
    suseconds_t tv_usec;    // used fot microseconds 
//The second is a microsecond value, which the computer knows but isn’t included with the time_t value.
};
*/
int	atoi_handle(char *av);
int	ft_strcmp(char *s1, char *s2);
uint64_t	get_time();
void	print_to_screen(char *string, t_philo *philo);
void	timer(int time);
void	philo_eat(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	*routine(t_philo	*philo);
void	timer(int time);
uint64_t	get_time(void);
void	print_to_screen(char *string, t_philo *philo);
# endif