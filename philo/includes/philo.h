/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:37 by shaas             #+#    #+#             */
/*   Updated: 2022/05/23 19:19:31 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# include "colours.h"

typedef struct s_time
{
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
}				t_time;

typedef struct s_philo
{
	unsigned int	last_eaten_at;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;//do we need?
	pthread_mutex_t	*right_fork;//do we need?
}				t_philo;

typedef struct s_all
{
	t_time			time;
	unsigned int	philo_num;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	unsigned int	stop_after_eat;
	pthread_mutex_t	print_mutex;
}				t_all;

t_all	*all(void);

bool	parser(int argc, char *argv[]);
bool	error_check(int argc, char *argv[]);

bool	create_threads(void);
bool	join_threads(void);

unsigned long	get_curr_time(void);

/*-- UTILS ---*/

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

#endif
