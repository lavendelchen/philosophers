/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:21:35 by shaas             #+#    #+#             */
/*   Updated: 2022/05/21 14:18:56 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static unsigned int	ft_atoui(const char *str)
{
	unsigned int	ui;

	ui = 0;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ui = ui * 10;
		ui = ui + (*str - '0');
		str++;
	}
	return (ui);
}

bool	parser(int argc, char *argv[])
{
	if (error_check(argc, argv) == true)
		return (true);
	all()->philos.philo_num = ft_atoui(argv[1]);
	all()->time.die = ft_atoui(argv[2]);
	all()->time.eat = ft_atoui(argv[3]);
	all()->time.sleep = ft_atoui(argv[4]);
	if (argv[5] != NULL)
		all()->stop_after_eat = ft_atoui(argv[5]);
	else
		all()->stop_after_eat = 0;
	printf("philos: %u\n", all()->philos.philo_num);
	printf("die: %u\n", all()->time.die);
	printf("eat: %u\n", all()->time.eat);
	printf("sleep: %u\n", all()->time.sleep);
	printf("stop_after_eat: %u\n", all()->stop_after_eat);
	return (false);
}
