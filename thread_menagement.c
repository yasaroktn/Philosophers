/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_menagement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:18:02 by yokten            #+#    #+#             */
/*   Updated: 2023/09/04 03:48:20 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	while (1)
	{
		if (philo_eat(philo, "has taken a fork"))
			break ;
	}
}

int	mutex_init(t_data	*philo)
{
	int i;

	i = -1;
	while (++i < philo->number_of_philosophers)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL))
			return (1);
	}
	pthread_mutex_init(&philo->print_mutex, NULL);
	pthread_mutex_init(&philo->died_mutex, NULL);
	pthread_mutex_init(&philo->time_eat_mutex, NULL);
	return (0);
}

void	thread_create(t_data	*philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		pthread_create(&philo->philosophers[i].th, NULL, &routine,
			&philo->philosophers[i]);
		philo->philosophers[i].who = i + 1;
		i += 2;
		usleep(100);
	}
	i = 1;
	while (i < philo->number_of_philosophers)
	{
		pthread_create(&philo->philosophers[i].th, NULL, &routine,
			&philo->philosophers[i]);
		philo->philosophers[i].who = i + 1;
		i += 2;
		usleep(100);
	}
}
