/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:30:23 by shaas             #+#    #+#             */
/*   Updated: 2022/06/01 13:50:47 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	parser_error(char *err_msg, short arg_num, bool wrong_usage)
{
	char	*arg_names[5];

	printf("%sError:%s %s", LIGHTRED, RESET, err_msg);
	if (arg_num != -1)
	{
		arg_names[0] = "number_of_philosophers";
		arg_names[1] = "time_to_die";
		arg_names[2] = "time_to_eat";
		arg_names[3] = "time_to_sleep";
		arg_names[4] = "number_of_times_each_philosopher_must_eat";
		printf("%s%s%s%s\n", BOLD, LIGHTBLUE, arg_names[arg_num - 1], RESET);
	}
	if (wrong_usage == true)
		printf("\nUsage: %s%s./philo [number_of_philosophers] [time_to_die] \
[time_to_eat] [time_to_sleep] %s\
%s(number_of_times_each_philosopher_must_eat)%s\n",
			BOLD, LIGHTBLUE, RESET, LIGHTBLUE, RESET);
	return (true);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static bool	is_number(char *str)
{
	if (str == NULL)
		return (false);
	if (*str != '+' && *str != '-' && ft_isdigit(*str) == 0)
		return (false);
	str++;
	if (*str == '\0' && ft_isdigit(*(str - 1)) == 0)
		return (false);
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (false);
		str++;
	}
	return (true);
}

static bool	is_in_range(char *str)
{
	char	*uint_max;

	if (*str == '-')
		return (false);
	if (*str == '+')
		str++;
	if (ft_strcmp("0", str) == 0)
		return (false);
	if (ft_strlen(str) > 10)
		return (false);
	if (ft_strlen(str) < 10)
		return (true);
	uint_max = "4294967295";
	while (*str != 0)
	{
		if (*str > *uint_max)
			return (false);
		if (*str < *uint_max)
			return (true);
		str++;
		uint_max++;
	}
	return (true);
}

bool	error_check(int argc, char *argv[])
{
	int		i;
	bool	is_error;

	if (argc < 5 || argc > 6)
		return (parser_error("Wrong number of arguments", -1, true));
	i = 1;
	is_error = false;
	while (argv[i] != NULL)
	{
		if (is_number(argv[i]) == false)
			is_error = parser_error("Numeric argument required for ", i, false);
		else if (is_in_range(argv[i]) == false)
			is_error = parser_error("Argument must be in between 1 and \
UINT_MAX for ", i, false);
		i++;
	}
	return (is_error);
}
