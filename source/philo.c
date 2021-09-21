#include "../include/philo.h"

int	ft_error(char *str)
{
	write(1, "Error: ", 7);
	write(1, str, ft_strlen(str));
	return (-1);
}

int	monitoring(t_data *data, int i)
{
	while (1)
	{
		i = 0;
		while (i++ < data->table->sum_philo)
		{
			if (timestamp() - data->philo[i].t_last_meal > data->table->time_die)
			{
				ft_message(data, data->philo->ph_id, DIED);
				return (1);
			}
			i = 0;
			while (i < data->table->sum_philo && data->philo[i].ate \
				<= data->table->must_eat)
				i++;
			if (i < data->table->sum_philo)
			{
				pthread_mutex_lock(&data->table->message);
				write (1, "THE END\n", 8);
				return (1);
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;
	t_data	data;

	if (argc < 5 || argc > 6)
		return (ft_error("Arguments not 5 or 6\n"));
	if (ft_parser(&table, argv, argc) < 0)
		return (ft_error("Wrong argunets\n"));
	data.table = &table;
	if (init(&data) < 0)
		return (ft_error("Init\n"));
	if (creating_philos(&data) < 0)
		return (ft_error("No create pthreads\n"));
	monitoring(&data, 0);
	if (mem_free(&data, 0) < 0)
		return (ft_error("Mem free\n"));
	return (0);
}