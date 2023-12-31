#include "philo.h"

void	init_mutex(t_philo *philo, int size)
{
	int				i;
	pthread_mutex_t	*mutex;

	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t) * size);
	if (!mutex)
		return ;
	while (i < size)
		pthread_mutex_init(&mutex[i++], NULL);
	philo->mutex = mutex;
	i = 1;
	philo[0].r_mutex = &mutex[0];
	philo[0].l_mutex = &mutex[size - 1];
	while (i < size)
	{
		philo[i].r_mutex = &mutex[i];
		philo[i].l_mutex = &mutex[i - 1];
		i++;
	}
}

void	set_basic(t_philo *philo, char **av)
{
	int	i;
	int	size;

	i = 0;
	size = ft_atoi(av[1]);
	while (i < size)
	{
		philo[i].philo_id = i + 1;
		philo[i].philo_count = size;
		philo[i].t_die = ft_atoi(av[2]);
		philo[i].t_eat = ft_atoi(av[3]);
		philo[i].t_sleep = ft_atoi(av[4]);
		philo[i].death = ft_atoi(av[2]);
		if (av[5])
			philo[i].max_eat_count = ft_atoi(av[5]);
		i++;
	}
}

void	init_philo(t_philo *philo, char **av, int size)
{
	pthread_mutex_t	*lock;
	int				i;
	int				*dead;
	int				*full;

	i = 0;
	lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(lock, NULL);
	dead = malloc(sizeof(int));
	full = malloc(sizeof(int));
	*dead = 0;
	*full = 0;
	set_basic(philo, av);
	while (i < size)
	{
		philo[i].lock = lock;
		philo[i].is_full = full;
		philo[i].ph_dead = dead;
		philo[i].hm_eat = 0;
		philo[i].ms = 0;
		philo[i].start = 0;
		philo[i].start_time = 0;
		i++;
	}
}
