#include "philo_bonus.h"

int	ft_error(char *str)
{
	write(1, "Error: ", 7);
	write(1, str, ft_strlen(str));
	return (-1);
}

int	main(int argc, char **argv)
{
	t_table	table;
	t_data	data;
	int		i;
	int		status;

	i = 0;
	if (argc < 5 || argc > 6)
		return (ft_error("Arguments not 5 or 6\n"));
	if (ft_parser(&table, argv, argc) < 0)
		return (ft_error("Wrong argunets\n"));
	data.table = &table;
	if (init(&data) < 0)
		return (ft_error("Init\n"));
	if (creating_philos(&data) < 0)
		return (ft_error("No create pthreads\n"));
	mem_free(&data, 0);
	waitpid(-1, &status, 0);
	while (i < data.table->sum_philo)
	{
		kill(data.philo[i].pid, SIGKILL);
		i++;
	}
	return (0);
}
