/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 08:49:00 by yokten            #+#    #+#             */
/*   Updated: 2023/08/29 15:59:40 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_assignment(t_data *flow, char	**av)
{
	flow->number_of_philosophers = ft_atoi(av[1]);
	flow->time_to_die = ft_atoi(av[2]);
	flow->time_to_eat = ft_atoi(av[3]);
	flow->time_to_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		flow->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		flow->number_of_times_each_philosopher_must_eat = -1;
}

int	args_control(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5 || ac > 6)
		return (1);
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
