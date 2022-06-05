/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:55:04 by shaas             #+#    #+#             */
/*   Updated: 2022/06/03 17:51:34 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_loop(unsigned int philo_num)
{
	while (all()->is_fail == false)
	{
		if (protected_print(philo_num, "is thinking", -1) == true
			|| take_forks(philo_num) == true
			|| eat(philo_num) == true
			|| (all()->stop_after_eat != 0
				&& all()->philo[philo_num].times_eaten >= all()->stop_after_eat)
			|| slep(philo_num) == true)
			return ;
	}
}

void	*routine(void *philo_num_p)
{
	unsigned int	philo_num;

	philo_num = *(unsigned int *)philo_num_p;
	while (all()->philo[all()->philo_num - 1].thread_id == 0
		&& all()->is_fail == false)
		ft_usleep(all()->philo_num);
	if (philo_num % 2 != 0)
		ft_usleep((all()->time.eat / 2) * 1000);
	philo_loop(philo_num);
	if (all()->philo[philo_num].left_fork != NULL)
		pthread_mutex_unlock(all()->philo[philo_num].left_fork);
	if (all()->philo[philo_num].right_fork != NULL)
		pthread_mutex_unlock(all()->philo[philo_num].right_fork);
	return (NULL);
}
