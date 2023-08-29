/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_menagement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:18:02 by yokten            #+#    #+#             */
/*   Updated: 2023/08/29 16:31:31 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_create(t_data	*philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
		pthread_create(philo->philosophers[i++], NULL, func, NULL);
}