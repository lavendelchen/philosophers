/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:12 by shaas             #+#    #+#             */
/*   Updated: 2022/05/20 14:51:08 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}

int	main(int argc, char *argv[])
{
	if (parser(argc, argv) == true)
		return (1);
	return (0);
}
