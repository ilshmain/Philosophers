#include "philo.h"

int	ft_error(char *str)
{
	write(1, "Error: ", 7);
	write(1, str, ft_strlen(str));
	return (-1);
}

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

static void	ft_putnbr_long(long long n)
{
	if (n == -9223372036854775807)
	{
		write(1, "−9223372036854775807", 23);
	}
	else if (n < 0)
	{		
		write(1, "-", 1);
		ft_putnbr_long(-n);
	}
	else if (n > 9)
	{
		ft_putnbr_long(n / 10);
		ft_putnbr_long(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_message(t_data *data, int ph_id, char *str)
{
	int			len;
	uint64_t	tt;

	len = 0;
	while (str[len])
		len++;
	tt = timestamp() - data->table->start_time;
	if (tt >= 0)
	{
		pthread_mutex_lock(&data->table->message);
		ft_putnbr_long(tt);
		ft_putchar(' ');
		ft_putnbr_long(ph_id);
		ft_putchar(' ');
		write(1, str, len);
		ft_putchar('\n');
		pthread_mutex_unlock(&data->table->message);
	}
}
