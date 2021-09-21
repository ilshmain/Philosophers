#include "../include/philo.h"

int	mem_free(t_data *data, int i)
{	
	while (i < data->table->sum_philo)
	{
		if (pthread_detach(data->philo[i].thread_id))
			return (-1);
		i++;
	}
	i = 0;
	while (i < data->table->sum_philo)
	{
		pthread_mutex_destroy(data->table->forks + i);
		i++;
	}
	pthread_mutex_destroy(&data->table->message);
	free(data->philo);
	free(data->table->forks);
	return (1);
}

int	init_mutex(t_table *table, t_data *d, int i)
{
	d->philo = malloc(sizeof(*d->philo) * d->table->sum_philo);
	d->table->forks = malloc(sizeof(*d->table->forks) * d->table->sum_philo);
	if (!d->philo || !d->table->forks)
		return (-1);
	while (table->sum_philo > i)
	{
		if (pthread_mutex_init(table->forks + i, NULL))
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&table->message, NULL))
		return (-1);
	return (1);
}

void	init_philosophers(t_data *d, int i)
{
	while (i < d->table->sum_philo)
	{
		d->philo[i].ph_id = i + 1;
		d->philo[i].left_fork = &d->table->forks[i];
		d->philo[i].right_fork = &d->table->forks[(i + 1) % d->table->sum_philo];
		d->philo[i].ate = 0;
		i++;
	}
}

int	init(t_data *data)
{
	int	i;

	i = 0;
	if (init_mutex(data->table, data, i) < 0)
		return (ft_error("Error init mutex\n"));
	init_philosophers(data, i);
	return (1);
}