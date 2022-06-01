/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:12 by shaas             #+#    #+#             */
/*   Updated: 2022/06/01 14:03:18 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_data(void) // needs to go
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

int	main(int argc, char *argv[])
{
	if (parser(argc, argv) == true)
		return (1);
	if (init_all() == true)
		return (free_all());
	if (create_threads() == true)
		all()->is_fail = true;
	//print_data();
	join_threads();
	return (free_destroy_all(all()->is_fail));
}
