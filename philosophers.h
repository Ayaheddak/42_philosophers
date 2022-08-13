/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:46:05 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/13 07:47:20 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
	int				nb_of_philo;
	int				tm_to_die;
	int				tm_to_eat;
	int				nb_of_ms_eat;
	t_philo			*philos;
	pthread_mutex_t *forks;
	pthread_mutex_t print;
}		t_data;

typedef struct s_philo
{
	int				id;
	int				fork_left;
	int				fork_right;
	unsigned long 	last_meal;
	unsigned int 	meals_count;
	t_data			data;
}		t_philo;

# endif