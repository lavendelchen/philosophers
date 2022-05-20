/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:21:35 by shaas             #+#    #+#             */
/*   Updated: 2022/05/20 14:55:37 by shaas            ###   ########.fr       */
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
	all()->arg.philos = ft_atoui(argv[1]);
	all()->arg.die = ft_atoui(argv[2]);
	all()->arg.eat = ft_atoui(argv[3]);
	all()->arg.sleep = ft_atoui(argv[4]);
	if (argv[5] != NULL)
		all()->arg.end_after_eat = ft_atoui(argv[5]);
	else
		all()->arg.end_after_eat = 0;
	printf("philos: %u\n", all()->arg.philos);
	printf("die: %u\n", all()->arg.die);
	printf("eat: %u\n", all()->arg.eat);
	printf("sleep: %u\n", all()->arg.sleep);
	printf("end_after_eat: %u\n", all()->arg.end_after_eat);
	return (false);
}
