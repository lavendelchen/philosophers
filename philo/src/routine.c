/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:55:04 by shaas             #+#    #+#             */
/*   Updated: 2022/05/31 16:41:23 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	take_fork(unsigned int philo_num, unsigned int fork_num)
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

	if (take_fork(philo_num, philo_num) == true ||
		all()->philo_num == 1)
		return (true);
	if (philo_num + 1 == all()->philo_num)
		so_dead = take_fork(philo_num, 0);
	else
		so_dead = take_fork(philo_num, philo_num + 1);
	return (so_dead);
}

bool	slep(unsigned int philo_num)
{
	if (protected_print(philo_num, "is sleeping", -1) == true)
		return (true);
	usleep(all()->time.sleep * 1000);
	return (false);
}

void	sleep_ms(size_t time) // maybe use to get more accurate sleeps
{
	size_t starttime = get_curr_time();
	while (get_curr_time() < starttime + time)
		usleep(all()->philo_num);
}

bool	eat(unsigned int philo_num)
{
	all()->philo[philo_num].last_eaten_at = get_curr_time();
	if (protected_print(philo_num, "is eating", -1) == true)
		return (true);
	all()->philo[philo_num].times_eaten++;
	usleep(all()->time.eat * 1000);
	pthread_mutex_unlock(all()->philo[philo_num].left_fork);
	pthread_mutex_unlock(all()->philo[philo_num].right_fork);
	all()->philo[philo_num].left_fork = NULL;
	all()->philo[philo_num].right_fork = NULL;
	return (false);
}

void	philo_loop(unsigned int philo_num)
{
	while (all()->is_fail == false)
	{
		if (protected_print(philo_num, "is thinking", -1) == true ||
			take_forks(philo_num) == true ||
			eat(philo_num) == true ||
			(all()->stop_after_eat != 0 &&
			all()->philo[philo_num].times_eaten >= all()->stop_after_eat) ||
			slep(philo_num) == true)
			return ;
	}
}

void	*routine(void *philo_num_p)
{
	unsigned int	philo_num;

	philo_num = *(unsigned int *)philo_num_p;
	while (all()->philo[all()->philo_num - 1].thread_id == 0 && all()->is_fail == false)
		usleep(all()->philo_num);
	if (philo_num % 2 != 0)
		usleep((all()->time.eat / 2) * 1000);
	philo_loop(philo_num);
	if (all()->philo[philo_num].left_fork != NULL)
		pthread_mutex_unlock(all()->philo[philo_num].left_fork);
	if (all()->philo[philo_num].right_fork != NULL)
		pthread_mutex_unlock(all()->philo[philo_num].right_fork);
	return (NULL);
}
