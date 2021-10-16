#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>
# include <limits.h>
# include <signal.h>

# define DIED		"died"
# define LEFT_FORK	"has taken a left fork"
# define RIGHT_FORK	"has taken a right fork"
# define EAT		"is eating"
# define SLEEP		"is slepping"
# define THINK		"is thinking"

typedef struct s_table
{
	sem_t		*forks;
	sem_t		*message;
	int			sum_philo;
	uint64_t	time_die;
	uint64_t	time_eat;
	uint64_t	time_sleep;
	uint64_t	start_time;
	int			must_eat;
}		t_table;

typedef struct s_philo
{
	pid_t			pid;
	int				ph_id;
	int				ate;
	uint64_t		t_last_meal;
	pthread_t		thread_id;
}			t_philo;

typedef struct s_data
{
	t_philo		*philo;
	t_table		*table;
	int			in_d;
}			t_data;

int			ft_error(char *str);
int			ft_parser(t_table *table, char **argv, int argc);
int			init(t_data *data);
int			creating_philos(t_data *data);
void		ft_sleep(uint64_t time);
void		ft_message(t_data *data, int ph_id, char *str);
uint64_t	timestamp(void);
int			mem_free(t_data *data, int i);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);

#endif