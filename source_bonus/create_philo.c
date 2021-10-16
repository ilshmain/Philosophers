#include "philo_bonus.h"

void	eating(t_data *data, t_philo *ph)
{
	sem_wait(data->table->forks);
	ft_message(data, ph->ph_id, LEFT_FORK);
	sem_wait(data->table->forks);
	ft_message(data, ph->ph_id, RIGHT_FORK);
	if (timestamp() - ph->t_last_meal > data->table->time_die)
		sem_wait(data->table->forks);
	ph->t_last_meal = timestamp();
	ft_message(data, ph->ph_id, EAT);
	ft_sleep(data->table->time_eat);
	sem_post(data->table->forks);
	sem_post(data->table->forks);
	ph->ate++;
	ft_message(data, ph->ph_id, SLEEP);
	ft_sleep(data->table->time_sleep);
	ft_message(data, ph->ph_id, THINK);
}

void	*life(void *v_data)
{
	t_data	*data;

	data = v_data;
	data->philo->t_last_meal = timestamp();
	data->philo->ph_id = data->in_d;
	while (1)
	{
		eating(data, data->philo);
	}
}

void	child(t_data *d)
{
	if (pthread_create(&d->philo->thread_id, NULL, life, d))
		exit (1);
	while (1)
	{
		usleep(500);
		if (timestamp() - d->philo->t_last_meal > d->table->time_die)
		{
			ft_message(d, d->philo->ph_id, DIED);
			exit (1);
		}
		if (d->philo->ate > d->table->must_eat \
			&& d->table->must_eat != INT_MAX)
		{
			exit (1);
		}
	}
}

int	creating_philos(t_data *data)
{
	int	i;

	i = 0;
	data->table->start_time = timestamp();
	while (i < data->table->sum_philo)
	{
		data->in_d = i;
		data->philo[i].pid = fork();
		usleep(50);
		if (data->philo[i].pid == 0)
		{
			child(data);
			exit (1);
		}
		else
			i++;
	}
	return (1);
}
