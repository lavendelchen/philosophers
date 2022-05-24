/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:37 by shaas             #+#    #+#             */
/*   Updated: 2022/05/24 02:47:06 by shaas            ###   ########.fr       */
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
	unsigned int	philo_num;
	pthread_t		thread_id;
	unsigned long	last_eaten_at;
	unsigned int	times_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	// state!! so that we can chill while other doesn't have forks
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

void	*routine(void *philo_num_p);

unsigned long	get_curr_time(void);

/*-- UTILS ---*/

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	protected_print(unsigned int philo_num, char *msg, int fork_num);

#endif
