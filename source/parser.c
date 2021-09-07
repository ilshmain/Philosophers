#include "../include/philo.h"

void	ft_init_pars(t_phil *philo, char **argv, int argc)
{
	philo->sum_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->sum_eat = ft_atoi(argv[5]);
	else
		philo->sum_eat = 0;
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

int	ft_parser(t_phil *philo, char **argv, int argc)
{
	if (check_argv(argv) < 0)
		return (-1);
	ft_init_pars(philo, argv, argc);
	if (philo->sum_philo <= 0 || philo->time_to_die <= 0 || philo->time_to_eat <= 0 \
	|| philo->time_to_sleep <= 0 || philo->sum_philo > 200)
		return (-1);
	else
		return (1);
}