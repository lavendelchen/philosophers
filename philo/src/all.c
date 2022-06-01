/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:57:35 by shaas             #+#    #+#             */
/*   Updated: 2022/06/01 13:59:08 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	free_all(void)
{
	free(all()->philo);
	free(all()->fork);
	return (1);
}

int	free_destroy_all(bool is_fail)
{
	unsigned int	i;

	i = 0;
	while (i < all()->philo_num)
	{
		pthread_mutex_destroy(&(all()->fork[i]));
		i++;
	}
	free_all();
	pthread_mutex_destroy(&(all()->print_mutex));
	return (is_fail);
}

static void	init_philo_data(unsigned int i)
{
	all()->philo[i].philo_num = i;
	all()->philo[i].thread_id = 0;
	all()->philo[i].last_eaten_at = 0;
	all()->philo[i].times_eaten = 0;
	all()->philo[i].left_fork = NULL;
	all()->philo[i].right_fork = NULL;
}

bool	init_all(void)
{
	unsigned int	i;

	all()->death = 0;
	all()->someone_died = false;
	all()->is_fail = false;
	all()->philo = malloc(sizeof(t_philo) * (all()->philo_num));
	all()->fork = malloc(sizeof(pthread_mutex_t) * (all()->philo_num));
	if (all()->philo == NULL || all()->fork == NULL)
		return (true);
	i = 0;
	while (i < all()->philo_num)
	{
		init_philo_data(i);
		if (pthread_mutex_init(&(all()->fork[i]), NULL) != 0)
			return (true);
		i++;
	}
	if (pthread_mutex_init(&(all()->print_mutex), NULL) != 0)
		return (true);
	get_curr_time();
	return (false);
}

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}
