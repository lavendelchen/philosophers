/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:12 by shaas             #+#    #+#             */
/*   Updated: 2022/05/21 14:16:41 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_philos(void)
{
	unsigned int	i;

	i = 0;
	while (i < all()->arg.philos)
	{
		printf("Philosopher %u has last eaten at %u\n", i + 1, all()->philo[i].last_eaten_at);
		i++;
	}
}

void	free_all(void)
{
	free(all()->philo);
}

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}

bool	init_philos(void)
{
	unsigned int	i;

	all()->philo = malloc(sizeof(t_philo) * (all()->arg.philos + 1));
	if (all()->philo == NULL)
		return (true);
	i = 0;
	while (i < all()->arg.philos)
	{
		all()->philo[i].last_eaten_at = 0;
		i++;
	}
	return (false);
}

int	main(int argc, char *argv[])
{
	if (parser(argc, argv) == true)
		return (1);
	if (init_philos() == true)
		return (1);
	print_philos();
	free_all();
	return (0);
}
