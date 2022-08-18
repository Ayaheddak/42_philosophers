/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 03:50:46 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/18 05:30:25 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

uint64_t	get_time()//get to mili
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_usec * 1000) + (current_time.tv_usec / 1000));
}

void	timer(int	time)
{
	uint64_t start;
	int	epsilon ;

	epsilon = 50;
	start = get_time();
	while (get_time() - start < time)
		usleep(epsilon);
}

void	print_to_screen(char *string, t_philo *philo)
{
	uint64_t	time;

	time = get_time() - philo->time_start;
	printf("%llu philo %d%s\n", time , philo->id, string);
}

// int main() {
//   struct timeval current_time;
//   gettimeofday(&current_time, NULL);
//   printf("seconds : %ld\n micro seconds : %ld",
//     current_time.tv_sec, current_time.tv_usec);

//   return 0;
// }