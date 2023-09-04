/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:05:03 by yokten            #+#    #+#             */
/*   Updated: 2023/09/04 00:15:55 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*flow;

	flow = malloc(sizeof(t_data));
	if (!flow)
		return (1);
	if (args_control(ac, av))
	{
		printf("Args Error\n");
		return (1);
	}
	args_assignment(flow, av);
	if (mutex_init(flow) || add_malloc(flow))
		return (1);
	thread_create(flow);
}
