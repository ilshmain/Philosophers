#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include "../libft/libft.h"

typedef struct every_phil
{
	int		sum_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		sum_eat;

}	t_phil;

int	ft_error(char *str);
int	ft_parser(t_phil *philo, char **argv, int argc);

#endif