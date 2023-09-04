/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:07:02 by yokten            #+#    #+#             */
/*   Updated: 2023/09/04 02:33:08 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	compute_time(t_philo	*philo)
{
	gettimeofday(&philo->timeval, NULL);
	return ((philo->timeval.tv_sec * 1000) + (philo->timeval.tv_usec / 1000));
}

int	philo_eat(t_philo	*philo, char *message)
{
	
}