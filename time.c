/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 03:50:46 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/21 15:04:30 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

uint64_t	get_time()//get to mili
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	timer(int	time)
{
	uint64_t start;
	int	epsilon ;

	epsilon = 100;
	start = get_time();
	while (get_time() - start < time)
		usleep(epsilon);
}

void	print_to_screen(char *string, t_philo *philo)
{
	uint64_t	time;

	time = get_time() - philo->data->start;
	pthread_mutex_lock(&philo->data->print);
	printf("%llu philo %d%s\n", time, philo->id, string);
	pthread_mutex_unlock(&philo->data->print);
	
}

// int main() {
//   struct timeval current_time;
//   gettimeofday(&current_time, NULL);
//   printf("seconds : %ld\n micro seconds : %ld",
//     current_time.tv_sec, current_time.tv_usec);

//   return 0;
// }