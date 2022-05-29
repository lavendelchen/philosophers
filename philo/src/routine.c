/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:55:04 by shaas             #+#    #+#             */
/*   Updated: 2022/05/29 23:35:20 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	take_fork(unsigned int philo_num, unsigned int fork_num)
{
	pthread_mutex_lock(&(all()->fork[fork_num]));
	if (all()->philo[philo_num].left_fork == NULL)
		all()->philo[philo_num].left_fork = &(all()->fork[fork_num]);
	else
		all()->philo[philo_num].right_fork = &(all()->fork[fork_num]); // can it happen that a philo will take another fork even though he already has one in his right hand
	if (all()->someone_died == true)
		return (true);
	protected_print(philo_num, "has taken a fork", fork_num); // fork_num for testing
	return (false);
}

bool	slep(unsigned int philo_num)
{
	if (all()->someone_died == true)
		return (true);
	protected_print(philo_num, "is sleeping", -1); // does this have to be before the unlocking to avoid wrong output?
	usleep(all()->time.sleep * 1000);
	return (all()->someone_died);
}

void	sleep_ms(size_t time)
{
	size_t starttime = get_curr_time();
	while (get_curr_time() < starttime + time)
		usleep(all()->philo_num);
}

bool	eat(unsigned int philo_num)
{
	all()->philo[philo_num].last_eaten_at = get_curr_time();
	if (all()->someone_died == true)
		return (true);
	protected_print(philo_num, "is eating", -1);
	all()->philo[philo_num].times_eaten++;
	usleep(all()->time.eat * 1000);
	pthread_mutex_unlock(all()->philo[philo_num].left_fork);
	pthread_mutex_unlock(all()->philo[philo_num].right_fork);
	all()->philo[philo_num].left_fork = NULL;
	all()->philo[philo_num].right_fork = NULL;
	return (false);
}

void	*routine(void *philo_num_p)
{
	unsigned int	philo_num;
	bool			so_dead;

	philo_num = *(unsigned int *)philo_num_p;
	while (all()->philo[all()->philo_num - 1].thread_id == 0 && all()->is_fail == false)
		usleep(all()->philo_num);
	if (philo_num % 2 != 0)
		usleep((all()->time.eat / 2) * 1000);
	if (all()->someone_died == true)
		return (NULL);
	while (all()->is_fail == false)
	{
		protected_print(philo_num, "is thinking", -1); // handle case of 1 philo
		if (take_fork(philo_num, philo_num) == true)
			break;
		if (all()->philo_num == 1)
			break;
		if (philo_num + 1 == all()->philo_num)
			so_dead = take_fork(philo_num, 0);
		else
			so_dead = take_fork(philo_num, philo_num + 1);
		if (so_dead == true || eat(philo_num) == true)
			break;
		if (all()->stop_after_eat != 0 &&
			all()->philo[philo_num].times_eaten >= all()->stop_after_eat)
			break;
		if (slep(philo_num) == true)
			break;
	}
	if (all()->philo[philo_num].left_fork != NULL)
		pthread_mutex_unlock(all()->philo[philo_num].left_fork);
	if (all()->philo[philo_num].right_fork != NULL)
		pthread_mutex_unlock(all()->philo[philo_num].right_fork);
	return (NULL);
}
