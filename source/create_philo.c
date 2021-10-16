#include "philo.h"

void	eating(t_data *data, t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	ft_message(data, ph->ph_id, LEFT_FORK);
	pthread_mutex_lock(ph->right_fork);
	ft_message(data, ph->ph_id, RIGHT_FORK);
	if (timestamp() - ph->t_last_meal > data->table->time_die)
		pthread_mutex_lock(ph->left_fork);
	ph->t_last_meal = timestamp();
	ft_message(data, ph->ph_id, EAT);
	ft_sleep(data->table->time_eat);
	ph->ate++;
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	ft_message(data, ph->ph_id, SLEEP);
	ft_sleep(data->table->time_sleep);
	ft_message(data, ph->ph_id, THINK);
}

void	*life(void *v_data)
{
	t_data	*data;
	t_philo	*ph;

	data = v_data;
	ph = data->philo + data->in_d;
	ph->t_last_meal = timestamp();
	while (1)
	{
		eating(data, ph);
	}
}

int	creating_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->table->sum_philo)
	{
		data->table->start_time = timestamp();
		data->in_d = i;
		if (pthread_create(&data->philo[i].thread_id, NULL, life, data))
			return (-1);
		usleep(50);
		i++;
	}
	return (1);
}
