/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_menagement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:18:02 by yokten            #+#    #+#             */
/*   Updated: 2023/08/31 05:18:16 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*v_philo)
{
	t_philo	philo;

	philo = *(t_philo *)v_philo;
	while (1)
	{
		if (philo_eat(philo))
			break;
	}
}

void	thread_create(t_data	*philo)
{
	int	i;

	i = -1;
	while (++i < philo->number_of_philosophers)
		pthread_create(&philo->philosophers[i].th, NULL, &routine,
			&philo->philosophers[i]);
}
