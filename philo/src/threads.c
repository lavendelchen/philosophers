/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:21:33 by shaas             #+#    #+#             */
/*   Updated: 2022/06/05 12:58:05 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_threads(void)
{
	unsigned int	i;

	i = 0;
	while (i < all()->philo_num)
	{
		if (all()->philo[i].thread_id != 0)
			pthread_join(all()->philo[i].thread_id, NULL);
		i++;
	}
	if (all()->philo_num != 1)
		all()->all_done = true;
	if (all()->death != 0)
		pthread_join(all()->death, NULL);
	all()->all_done = true;
}

bool	create_threads(void)
{
	unsigned int	i;

	i = 0;
	while (i < all()->philo_num)
	{
		if (pthread_create(&(all()->philo[i].thread_id), NULL,
				&routine, &(all()->philo[i].philo_num)) != 0)
			return (true);
		i++;
	}
	if (pthread_create(&(all()->death), NULL, &death, NULL) != 0)
		return (true);
	return (false);
}
