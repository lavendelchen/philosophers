 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:12 by shaas             #+#    #+#             */
/*   Updated: 2022/05/28 20:40:02 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_data(void)
{
	unsigned int	i;
	unsigned int	colour;

	i = 0;
	colour = 31;
	pthread_mutex_lock(&(all()->print_mutex));
	printf("Current timestamp: %lu\n", get_curr_time());
	printf("philos: %u\n", all()->philo_num);
	printf("die: %u\n", all()->time.die);
	printf("eat: %u\n", all()->time.eat);
	printf("sleep: %u\n", all()->time.sleep);
	printf("stop_after_eat: %u\n", all()->stop_after_eat);
	printf("\n");
	while (i < all()->philo_num)
	{
		printf("\e[%dm%sPhilosopher %u\e[0m\n", colour, BOLD, i + 1);
		printf("    has last eaten at %lu\n", all()->philo[i].last_eaten_at);
		#ifndef __APPLE__
		printf("    has the thread ID %lu\n", all()->philo[i].thread_id);
		#endif
		printf("    has the fork at memory address %p in his left hand\n", all()->philo[i].left_fork);
		printf("    has the fork at memory address %p in his right hand\n", all()->philo[i].right_fork);
		i++;
		colour++;
		if (colour == 37)
			colour = 31;
	}
	pthread_mutex_unlock(&(all()->print_mutex));
}

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

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}

bool	init_all(void)
{
	unsigned int	i;

	all()->philo = malloc(sizeof(t_philo) * (all()->philo_num));
	all()->fork = malloc(sizeof(pthread_mutex_t) * (all()->philo_num));
	if (all()->philo == NULL || all()->fork == NULL)
		return (true);
	i = 0;
	while (i < all()->philo_num)
	{
		all()->philo[i].philo_num = i;
		all()->philo[i].thread_id = 0;
		all()->philo[i].last_eaten_at = 0;
		all()->philo[i].times_eaten = 0;
		all()->philo[i].left_fork = NULL;
		all()->philo[i].right_fork = NULL;
		if (pthread_mutex_init(&(all()->fork[i]), NULL) != 0)
			return (true);
		i++;
	}
	if (pthread_mutex_init(&(all()->print_mutex), NULL) != 0)
		return (true);
	get_curr_time();
	return (false);
}

int	main(int argc, char *argv[])
{
	if (parser(argc, argv) == true)
		return (1);
	if (init_all() == true)
		return (free_all());
	if (create_threads() == true)
		return (free_destroy_all(true));
	//print_data();
	join_threads();
	return (free_destroy_all(false));
}
