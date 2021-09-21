#include "../include/philo.h"

void	ft_init_pars(t_table *table, char **argv, int argc)
{
	table->sum_philo = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = 0;
}

int	check_argv(char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if ((argv[i][k] > 1 && argv[i][k] < 47) || (argv[i][k] > 58 && argv[i][k] < 127))
				return (-1);
			k++;
		}
		i++;
	}
	return (1);
}

int	ft_parser(t_table *table, char **argv, int argc)
{
	if (check_argv(argv) < 0)
		return (-1);
	ft_init_pars(table, argv, argc);
	if (table->sum_philo <= 2 || table->time_die <= 0 || table->time_eat <= 0 \
	|| table->time_sleep <= 0 || table->sum_philo > 200 || (argc == 6 && table->sum_philo <= 0))
		return (-1);
	else
		return (1);
}