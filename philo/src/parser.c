/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:21:35 by shaas             #+#    #+#             */
/*   Updated: 2022/05/18 19:29:11 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	parser_error(char *err_msg, bool wrong_usage)
{
	printf("%sError: %s%s\n", LIGHTRED, err_msg, RESET);
	if (wrong_usage == true)
		printf("Usage: %s%s./philo [number_of_philosophers] [time_to_die] \
[time_to_eat] [time_to_sleep] %s%s(number_of_times_each_philosopher_must_eat)%s\n",
				BOLD, LIGHTBLUE, RESET, LIGHTBLUE, RESET);
	return (true);
}

bool	parser(int argc, char *argv[], t_arg *arg)
{
	if (argc < 5 || argc > 6)
		return (parser_error("Wrong number of arguments", true));
	return (false);
}
