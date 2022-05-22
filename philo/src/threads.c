/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:21:33 by shaas             #+#    #+#             */
/*   Updated: 2022/05/22 21:04:28 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	join_threads(void)
{
	unsigned int	i;

	i = 0;
	while (i < all()->philo_num)
	{
		if (pthread_join(all()->philo[i].thread_id, NULL) != 0)
			return (true);
		i++;
	}
	return (false);
}

void	*routine(void *thread_id)
{
	printf("this is the thread with process id %lu\n", *(pthread_t *)thread_id);
	return (NULL);
}

bool	create_threads(void)
{
	unsigned int	i;

	i = 0;
	while (i < all()->philo_num)
	{
		if (pthread_create(&(all()->philo[i].thread_id), NULL, &routine, &(all()->philo[i].thread_id)) != 0)
			return (true);
		i++;
	}
	return (false);
}
