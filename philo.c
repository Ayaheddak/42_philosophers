/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:08:35 by aheddak           #+#    #+#             */
/*   Updated: 2022/08/13 04:59:48 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
-threads are sharing memories
-pthread_t is an integer used to identify the threads system;

-int pthread_create() : function to creat thread, on succeess return 0 on error returns an error number 
takes 4 args : the first arg is a pointer to thread the second arg specifies attributes if the value is Null then default attributes shall be used
the third arg is name of func to be executed for thread to be created and The fourth argument is used to pass arguments to the function

-int pthread_join() : fucntion for threads is the eque of wait

-memset: is used to fill a block of memory with a particular value


-race conditions : 


-usleep :


-mutexes : 


-pthread_detach: "int phread_detach(Pthread_t thread)" la structure sera detruite a la terminaison du thread and ne sera pas possible de retrouver somn pointeur retour avec pthread_join


- pthread_mutex_init: 

if successful return 0 
-pthread_mutex_destroy:



- pthread_mutex_lock:


- pthread_mutex_unlock:

- pthread_exit() : pour quitter le thread on prefere faire ca(dans le param il contient la valeur de reteur )

- to solve prb race condts used mutex;
       
- wait pour laisser le temps au thread pour s'executer
- pour eviter les conflits en utilise mutex
- mutex_init and mutex_destory just for initialize
*/
// void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t		i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		((unsigned char *)b)[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (b);
// }
// if lock =1 doing smtg;
// semaphore

int x= 2;
int lock = 0;
pthread_mutex_t mutex;

void	*dowork()
{
	for (int i = 0; i < 10000000; i++)
	{
		if (lock == 1)
		{
			//wait
		}
		lock = 1;
		x++;
		lock = 0;
		//printf("value of x (1)---> %d\n", x);
	}
}

void	*dowork2()
{
	//x++;
	printf("value of x (2) ---> %d\n", x);
	
}
//the same ideas cuz processes can contain multiple treads

int main()
{
	pthread_t	t1;
	pthread_t	t2;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, dowork, NULL) != 0) 
		return (1);
	if (pthread_create(&t2, NULL, dowork2, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	pthread_mutex_destroy(&mutex);
	return (0);
}