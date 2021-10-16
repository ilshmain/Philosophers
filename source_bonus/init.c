#include "philo_bonus.h"

int	mem_free(t_data *data, int i)
{	
	while (i < data->table->sum_philo)
	{
		if (pthread_detach(data->philo[i].thread_id))
			return (-1);
		i++;
	}
	free(data->philo);
	return (1);
}

int	init_forks(t_table *table, t_data *d)
{
	d->philo = malloc(sizeof(*d->philo) * d->table->sum_philo);
	if (!d->philo)
		return (-1);
	sem_unlink("forks");
	sem_unlink("message");
	table->forks = sem_open("forks", O_CREAT, S_IRWXU, table->sum_philo);
	if (table->forks == 0)
		exit(1);
	table->message = sem_open("message", O_CREAT, S_IRWXU, 1);
	if (table->message == 0)
		exit(1);
	return (1);
}

void	init_philosophers(t_data *d, int i)
{
	while (i < d->table->sum_philo)
	{
		d->philo[i].ph_id = i + 1;
		d->philo[i].ate = 0;
		i++;
	}
}

int	init(t_data *data)
{
	if (init_forks(data->table, data) < 0)
		return (ft_error("Error init mutex\n"));
	init_philosophers(data, 0);
	return (1);
}
