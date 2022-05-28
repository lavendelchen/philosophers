/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:21:33 by shaas             #+#    #+#             */
/*   Updated: 2022/05/28 20:35:48 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_threads(void)
{
	unsigned int	i;

	i = 0;
	while (i < all()->philo_num)
	{
		pthread_join(all()->philo[i].thread_id, NULL) // doesn't work, why?
		i++;
	}
}

bool	create_threads(void)
{
	unsigned int	i;

	i = 0;
	while (i < all()->philo_num)
	{
		if (pthread_create(&(all()->philo[i].thread_id), NULL, &routine, &(all()->philo[i].philo_num)) != 0)
			return (true); // will be problem if threads are going and are not joined??
		i++;
	}
	return (false);
}
