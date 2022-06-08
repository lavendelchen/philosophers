/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:12 by shaas             #+#    #+#             */
/*   Updated: 2022/06/08 19:41:38 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	if (parser(argc, argv) == true)
		return (1);
	if (init_all() == true)
		return (free_all());
	if (create_threads() == true)
		all()->is_fail = true;
	join_threads();
	return (free_destroy_all(all()->is_fail));
}
