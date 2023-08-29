/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:05:03 by yokten            #+#    #+#             */
/*   Updated: 2023/08/29 13:56:06 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*flow;

	flow = malloc(sizeof(t_data));
	add_malloc(flow);
	if (args_control(ac, av))
	{
		printf("Args Error\n");
		return (1);
	}
	args_assignment(flow);
	thread_create(flow);
}
