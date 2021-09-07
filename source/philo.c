#include "../include/philo.h"

int	ft_error(char *str)
{
	write(1, "Error: ", 7);
	write(1, str, ft_strlen(str));
	return (-1);
}

int	main(int argc, char **argv)
{
	t_phil philo;

	if (argc < 5 || argc > 6)
		return (ft_error("Arguments not 5 or 6\n"));
	if (ft_parser(&philo, argv, argc) < 0)
		return (ft_error("Wrong argunets\n"));
	printf("%d", argc);
}