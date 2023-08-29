/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_menagement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:00:39 by yokten            #+#    #+#             */
/*   Updated: 2023/08/29 16:16:14 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_malloc(t_data	*flow)
{
	flow->fork = malloc(sizeof(int) * flow->number_of_philosophers);
	flow->philosophers = malloc(sizeof(int) * flow->number_of_philosophers);
}