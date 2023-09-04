/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_menagement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:00:39 by yokten            #+#    #+#             */
/*   Updated: 2023/09/03 20:28:04 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	add_malloc(t_data	*flow)
{
	flow->fork = malloc(sizeof(pthread_mutex_t) * flow->number_of_philosophers);
	flow->philosophers = malloc(sizeof(int) * flow->number_of_philosophers);
	if (!flow->fork || !flow->philosophers)
		return (1);
	return (0);
}