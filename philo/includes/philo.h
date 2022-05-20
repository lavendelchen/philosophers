/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:06:37 by shaas             #+#    #+#             */
/*   Updated: 2022/05/20 16:05:28 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "colours.h"

typedef struct s_arg
{
	unsigned int	philos;
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	end_after_eat;
}				t_arg;

typedef struct s_philo
{
	unsigned int	last_eaten_at;
	bool			fork;
	
}				t_philo;

typedef struct s_all
{
	t_arg	arg;
	t_philo	*philo;
}				t_all;

t_all	*all(void);

bool	parser(int argc, char *argv[]);
bool	error_check(int argc, char *argv[]);

/*-- UTILS ---*/

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

#endif
