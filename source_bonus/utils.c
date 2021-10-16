#include "philo_bonus.h"

int	ft_strncmp(const char *p1, const char *p2, size_t n)
{
	size_t	k;

	k = 0;
	if (n == 0)
		return (0);
	while (k < n - 1)
	{
		if (p1[k] == '\0' && p2[k] == '\0')
			return (0);
		if ((p1[k] - p2[k]) == 0)
			k++;
		else
			break ;
	}
	return ((unsigned char)p1[k] - (unsigned char)p2[k]);
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
		sem_wait(data->table->message);
		ft_putnbr_long(tt);
		ft_putchar(' ');
		ft_putnbr_long(ph_id + 1);
		ft_putchar(' ');
		write(1, str, len);
		ft_putchar('\n');
	}
	if (ft_strncmp(str, DIED, 4))
		sem_post(data->table->message);
}
