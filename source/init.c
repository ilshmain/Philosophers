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
		if (pthread_mutex_destroy(data->table->forks + i))
			return (-1);
		i++;
	}
	if (pthread_mutex_destroy(&data->table->message))
		return (-1);
	free(data->philo);
	free(data->table->forks);
	return (1);
}

int	allocation(t_data *data)
{
	data->philo = malloc(sizeof(*data->philo) * data->table->sum_philo);
	if (!data->philo)
		return (-1);
	data->table->forks = malloc(sizeof(*data->table->forks) * data->table->sum_philo);
	if (!data->table->forks)
		return (-1);
	return (1);
}

int	init_mutex(t_table *table, int i)
{
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
	if (allocation(data) < 0)
		return (ft_error("Error allocation\n"));
	if (init_mutex(data->table, i) < 0)
		return (ft_error("Error init mutex\n"));
	init_philosophers(data, i);
	return (1);
}