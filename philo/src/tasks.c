/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:32:14 by shaas             #+#    #+#             */
/*   Updated: 2022/06/01 16:19:26 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	take_fork(unsigned int philo_num, unsigned int fork_num)
{
	pthread_mutex_lock(&(all()->fork[fork_num]));
	if (all()->philo[philo_num].left_fork == NULL)
		all()->philo[philo_num].left_fork = &(all()->fork[fork_num]);
	else
		all()->philo[philo_num].right_fork = &(all()->fork[fork_num]);
	if (protected_print(philo_num, "has taken a fork", fork_num) == true)
		return (true); // fork_num for testing
	return (false);
}

bool	take_forks(unsigned int philo_num)
{
	bool	so_dead;

	if (take_fork(philo_num, philo_num) == true
		|| all()->philo_num == 1)
		return (true);
	if (philo_num + 1 == all()->philo_num)
		so_dead = take_fork(philo_num, 0);
	else
		so_dead = take_fork(philo_num, philo_num + 1);
	return (so_dead);
}

bool	eat(unsigned int philo_num)
{
	all()->philo[philo_num].last_eaten_at = get_curr_time();
	if (protected_print(philo_num, "is eating", -1) == true)
		return (true);
	all()->philo[philo_num].times_eaten++;
	ft_usleep(all()->time.eat * 1000);
	pthread_mutex_unlock(all()->philo[philo_num].left_fork);
	pthread_mutex_unlock(all()->philo[philo_num].right_fork);
	all()->philo[philo_num].left_fork = NULL;
	all()->philo[philo_num].right_fork = NULL;
	return (false);
}

bool	slep(unsigned int philo_num)
{
	if (protected_print(philo_num, "is sleeping", -1) == true)
		return (true);
	ft_usleep(all()->time.sleep * 1000);
	return (false);
}
