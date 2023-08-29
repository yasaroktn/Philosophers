/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:13:32 by yokten            #+#    #+#             */
/*   Updated: 2023/08/29 15:54:48 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	int		*fork;
}	t_data;

int		args_control(int ac, char **av);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	add_malloc(t_data	*flow);
void	thread_create(t_data	*philo);
void	args_assignment(t_data *flow, char	**av);

#endif