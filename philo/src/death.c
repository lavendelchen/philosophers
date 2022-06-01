/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:04:32 by shaas             #+#    #+#             */
/*   Updated: 2022/06/01 17:46:59 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*death(void *arg)
{
	unsigned int	i;
	unsigned long	curr_time;

	(void)arg;
	while (true)
	{
		i = 0;
		while (i < all()->philo_num)
		{
			curr_time = get_curr_time();
			//if (all()->philo[i].last_eaten_at > )
			if (curr_time >= all()->philo[i].last_eaten_at + all()->time.die)
			{
				protected_print(i, "died", -1);
				all()->someone_died = true;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
