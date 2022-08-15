/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:46:05 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/15 09:52:51 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
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
	int				nb_of_ms_eat;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}		t_data;

typedef struct s_philo
{
	int				id;
	int				fork_left;
	int				fork_right;
	unsigned long 	last_meal;
	unsigned int 	meals_count;
	pthread_t		th;
	t_data			*data;
}		t_philo;
int	atoi_handle(char *av);
int	ft_strcmp(char *s1, char *s2);

# endif