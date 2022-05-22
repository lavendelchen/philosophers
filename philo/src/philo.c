/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:12 by shaas             #+#    #+#             */
/*   Updated: 2022/05/22 21:04:36 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_data(void)
{
	unsigned int	i;
	unsigned int	colour;

	i = 0;
	colour = 31;
	printf("philos: %u\n", all()->philo_num);
	printf("die: %u\n", all()->time.die);
	printf("eat: %u\n", all()->time.eat);
	printf("sleep: %u\n", all()->time.sleep);
	printf("stop_after_eat: %u\n", all()->stop_after_eat);
	printf("\n");
	while (i < all()->philo_num)
	{
		printf("\e[%dm%sPhilosopher %u\e[0m\n", colour, BOLD, i + 1);
		printf("    has last eaten at %u\n", all()->philo[i].last_eaten_at);
		printf("    has the thread ID %lu\n", all()->philo[i].thread_id);
		printf("    has the fork at memory address %p in his left hand\n", all()->philo[i].left_fork);
		printf("    has the fork at memory address %p in his right hand\n", all()->philo[i].right_fork);
		i++;
		colour++;
		if (colour == 37)
			colour = 31;
	}
}

void	free_all(void)
{
	free(all()->philo);
	free(all()->fork);
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
	all()->fork = malloc(sizeof(unsigned int) * (all()->philo_num));
	if (all()->philo == NULL || all()->fork == NULL)
		return (true);
	i = 0;
	while (i < all()->philo_num)
	{
		all()->philo[i].last_eaten_at = 0;
		all()->philo[i].thread_id = 0;
		all()->philo[i].left_fork = NULL;
		all()->philo[i].right_fork = NULL;
		all()->fork[i] = 0;
		i++;
	}
	return (false);
}

int	main(int argc, char *argv[])
{
	if (parser(argc, argv) == true)
		return (1);
	if (init_all() == true)
		return (1);
	if (create_threads() == true)
		return (1);
	//print_data();
	if (join_threads() == true)
		return (1);
	free_all();
	return (0);
}
