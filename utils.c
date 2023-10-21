#include "philo.h"

void	gettime(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	gettimeofday(&philo->tv, NULL);
	philo->ms = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	if (philo->start == 0)
		philo->start = philo->ms;
	philo->start_time = (philo->ms) - (philo->start);
	pthread_mutex_unlock(philo->lock);
}

void	go_kill(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
	{
		printf("%ld %d is died\n", philo->start_time, philo->philo_id);
		*philo->ph_dead = 1;
	}
	pthread_mutex_unlock(philo->lock);
}

int	ft_usleep(t_philo *philo, long ms)
{
	long	time;

	gettime(philo);
	time = philo->start_time;
	while (philo->start_time < (ms + time))
	{
		gettime(philo);
		if (philo->start_time > philo->death)
		{
			go_kill(philo);
			return (0);
		}
		usleep(100);
	}
	return (1);
}

int	ft_atoi(char *s)
{
	int		i;
	int		sign;
	long	temp;

	i = 0;
	sign = 1;
	temp = 0;
	while (s[i] <= 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= 32)
	{
		temp = (temp * 10) + (s[i] - 48);
		if (temp * sign > 2147483647)
			return (0);
		if (temp * sign < -2147483648)
			return (-1);
		i++;
	}
	return (temp * sign);
}

int	is_digit(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] < '0' || arr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
