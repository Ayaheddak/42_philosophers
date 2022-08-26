/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 03:50:46 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/26 05:47:28 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

uint64_t	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	timer(int time)
{
	uint64_t	start;
	int			epsilon;

	epsilon = 100;
	start = get_time();
	while (get_time() - start < (uint64_t)time)
		usleep(epsilon);
}

void	print_to_screen(char *string, t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->print);
	time = get_time() - philo->data->start;
	printf("%llu philo %d%s\n", time, philo->id, string);
	pthread_mutex_unlock(&philo->data->print);
}
