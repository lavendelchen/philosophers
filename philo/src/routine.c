/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:55:04 by shaas             #+#    #+#             */
/*   Updated: 2022/05/29 19:25:41 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(unsigned int philo_num, unsigned int fork_num)
{
	pthread_mutex_lock(&(all()->fork[fork_num]));
	if (all()->philo[philo_num].left_fork == NULL)
		all()->philo[philo_num].left_fork = &(all()->fork[fork_num]);
	else
		all()->philo[philo_num].right_fork = &(all()->fork[fork_num]); // can it happen that a philo will take another fork even though he already has one in his right hand
	protected_print(philo_num, "has taken a fork", fork_num); // fork_num for testing
}

void	slep(unsigned int philo_num)
{
	protected_print(philo_num, "is sleeping", -1); // does this have to be before the unlocking to avoid wrong output?
	usleep(all()->time.sleep * 1000);
}

void	eat(unsigned int philo_num)
{
	all()->philo[philo_num].last_eaten_at = get_curr_time();
	protected_print(philo_num, "is eating", -1);
	usleep(all()->time.eat * 1000);
	all()->philo[philo_num].times_eaten++;
	pthread_mutex_unlock(all()->philo[philo_num].left_fork);
	pthread_mutex_unlock(all()->philo[philo_num].right_fork);
	all()->philo[philo_num].left_fork = NULL;
	all()->philo[philo_num].right_fork = NULL;
}

void	*routine(void *philo_num_p)
{
	unsigned int	philo_num;

	philo_num = *(unsigned int *)philo_num_p;
	while (all()->philo[all()->philo_num - 1].thread_id == 0)
		usleep(all()->philo_num);
	while (true)
	{
		protected_print(philo_num, "is thinking", -1); // handle case of 1 philo
		if ((philo_num % 2 != 0 && all()->philo[philo_num].times_eaten % 2 != 0) ||
			(philo_num % 2 == 0 && all()->philo[philo_num].times_eaten % 2 == 0))
			usleep(all()->time.eat / 2 * 1000); // wie zum fick machen wir das dass die nicht in den death loop kommen
		take_fork(philo_num, philo_num);
		if (philo_num + 1 == all()->philo_num)
			take_fork(philo_num, 0);
		else
			take_fork(philo_num, philo_num + 1);
		eat(philo_num);
		if (all()->stop_after_eat != 0 && all()->philo[philo_num].times_eaten >= all()->stop_after_eat)
			break;
		slep(philo_num);
	}
	return (NULL);
}
