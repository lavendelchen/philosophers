/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:37 by shaas             #+#    #+#             */
/*   Updated: 2022/06/05 13:04:06 by shaas            ###   ########.fr       */
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
}				t_philo;

typedef struct s_all
{
	t_time			time;
	unsigned int	philo_num;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	unsigned int	stop_after_eat;
	pthread_t		death;
	pthread_mutex_t	print_mutex;
	bool			someone_died;
	bool			is_fail;
	bool			all_done;
}				t_all;

/*--- PARSING ---*/

bool			parser(int argc, char *argv[]);
bool			error_check(int argc, char *argv[]);

/*--- MANAGE DATA ---*/

t_all			*all(void);
bool			init_all(void);
int				free_destroy_all(bool is_fail);
int				free_all(void);

/*--- MANAGE THREADS ---*/

bool			create_threads(void);
void			join_threads(void);

/*--- MANAGE PHILOS ---*/

void			*routine(void *philo_num_p);
bool			take_forks(unsigned int philo_num);
bool			eat(unsigned int philo_num);
bool			slep(unsigned int philo_num);
void			*death(void *arg);

/*--- UTILS ---*/

size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_usleep(unsigned long time);
bool			protected_print(unsigned int philo_num, char *msg,
					int fork_num);
unsigned long	get_curr_time(void);

#endif
