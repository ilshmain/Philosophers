#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include "../libft/libft.h"

# define DIED		"died"
# define LEFT_FORK	"has taken a left fork"
# define RIGHT_FORK	"has taken a right fork"
# define EAT		"is eating"
# define SLEEP		"is slepping"
# define THINK		"is thinking"

typedef struct s_table
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		message;
	int					sum_philo;
	uint64_t			time_die;
	uint64_t			time_eat;
	uint64_t			time_sleep;
	uint64_t			start_time;
	int					must_eat;

}	t_table;

typedef struct s_philo
{
	int					ph_id;
	int					ate;
	uint64_t			t_last_meal;
	pthread_t			thread_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}			t_philo;

typedef struct s_data
{
	t_philo		*philo;
	t_table		*table;
	int			ind_cur;
}			t_data;

int			ft_error(char *str);
int			ft_parser(t_table *table, char **argv, int argc);
int			init(t_data *data);
int			creating_philos(t_data *data);
void		ft_sleep(uint64_t time);
void		ft_message(t_data *data, int ph_id, char *str);
uint64_t	timestamp(void);

int			mem_free(t_data *data, int i);

#endif