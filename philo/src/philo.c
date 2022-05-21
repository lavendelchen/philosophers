/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:12 by shaas             #+#    #+#             */
/*   Updated: 2022/05/21 14:47:51 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_philos(void)
{
	unsigned int	i;

	i = 0;
	while (i < all()->philos.philo_num)
	{
		printf("Philosopher %u has last eaten at %u\n", i + 1, all()->philos.philo[i].last_eaten_at);
		i++;
	}
}

void	free_all(void)
{
	free(all()->philos.philo);
}

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}

bool	init_philos(void)
{
	unsigned int	i;

	all()->philos.philo = malloc(sizeof(t_philo) * (all()->philos.philo_num + 1));
	if (all()->philos.philo == NULL)
		return (true);
	i = 0;
	while (i < all()->philos.philo_num)
	{
		all()->philos.philo[i].last_eaten_at = 0;
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
