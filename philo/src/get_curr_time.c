/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:05:27 by shaas             #+#    #+#             */
/*   Updated: 2022/05/23 19:15:40 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static unsigned long	calculate_tv_to_usec(struct timeval tv)
{
	unsigned long	usec;

	usec = tv.tv_sec;
	usec = usec * 1000000;
	usec = usec + tv.tv_usec;
	return (usec);
}

unsigned long	get_curr_time(void)
{
	struct timeval			tv;
	static unsigned long	starttime;
	unsigned long			currtime;

	if (gettimeofday(&tv, NULL) != 0)
		printf("%sError: gettimeofday not working properly%s\n", RED, RESET);
	if (starttime == 0)
	{
		starttime = calculate_tv_to_usec(tv);
		return (0);
	}
	currtime = calculate_tv_to_usec(tv);
	return ((currtime - starttime) / 1000);
}
