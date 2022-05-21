/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:37 by shaas             #+#    #+#             */
/*   Updated: 2022/05/21 14:42:27 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

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
}				t_philo;

typedef struct s_philos
{
	unsigned int	philo_num;
	t_philo			*philo;
	bool			*fork;
	//mutex			*mutex;
}				t_philos;

typedef struct s_all
{
	t_philos		philos;
	t_time			time;
	unsigned int	stop_after_eat;
}				t_all;

t_all	*all(void);

bool	parser(int argc, char *argv[]);
bool	error_check(int argc, char *argv[]);

/*-- UTILS ---*/

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

#endif
