/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:13:32 by yokten            #+#    #+#             */
/*   Updated: 2023/09/04 01:49:56 by yokten           ###   ########.fr       */
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
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	died_mutex;
	pthread_mutex_t	time_eat_mutex;
	t_philo			*philosophers;
}	t_data;

typedef struct s_philo
{
	pthread_t		th;
	int				who;
	int				real_time;
	int				start_time;
	struct timeval	timeval;
}	t_philo;

int		args_control(int ac, char **av);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		add_malloc(t_data	*flow);
int		mutex_init(t_data	*philo);
int		philo_eat(t_philo	*philo, char *message);
int		compute_time(t_philo	*philo);
void	thread_create(t_data	*philo);
void	args_assignment(t_data *flow, char	**av);
void	*routine(void	*v_philo);

#endif