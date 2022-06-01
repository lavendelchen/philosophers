/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:51:42 by shaas             #+#    #+#             */
/*   Updated: 2022/06/01 16:18:45 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* NULL string returns length 0 */
size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	if (str == NULL)
		return (0);
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i] || s1[i] == 0 || s2[i] == 0)
			return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
		i++;
	}
	return (0);
}

void	ft_usleep(unsigned long time)
{
	unsigned long	goaltime;

	goaltime = (get_curr_time() * 1000) + time;
	while (get_curr_time() * 1000 < goaltime)
		usleep(all()->philo_num);
}

bool	protected_print(unsigned int philo_num, char *msg, int fork_num)
{
	pthread_mutex_lock(&(all()->print_mutex));
	if (all()->someone_died == true)
	{
		pthread_mutex_unlock(&(all()->print_mutex));
		return (true);
	}
	printf("%lu %u %s", get_curr_time(), philo_num + 1, msg);
	if (fork_num >= 0)
		printf(", it is fork number %d\n", fork_num + 1);
	else
		printf("\n");
	pthread_mutex_unlock(&(all()->print_mutex));
	return (false);
}
