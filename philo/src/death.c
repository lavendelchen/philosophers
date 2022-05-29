/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:04:32 by shaas             #+#    #+#             */
/*   Updated: 2022/05/29 22:50:42 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*death(void *arg)
{
	unsigned int	i;

	(void)arg;
	i = all()->philo_num;
	while (i == all()->philo_num)
	{
		i = 0;
		while (i < all()->philo_num)
		{
			if (get_curr_time() >= all()->philo[i].last_eaten_at + all()->time.die)
			{
				protected_print(i, "died", -1);
				all()->someone_died = true;
				break;
			}
			i++;
		}
	}
	return (NULL);
}
