/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:04:32 by shaas             #+#    #+#             */
/*   Updated: 2022/06/08 19:39:20 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*death(void *arg)
{
	unsigned int	i;

	(void)arg;
	while (all()->all_done == false)
	{
		i = 0;
		while (i < all()->philo_num)
		{
			if ((all()->stop_after_eat == 0
					|| all()->philo[i].times_eaten < all()->stop_after_eat)
				&& get_curr_time()
				>= all()->philo[i].last_eaten_at + all()->time.die)
			{
				protected_print(i, "died");
				all()->someone_died = true;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
