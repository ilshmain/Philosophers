#include "../include/philo.h"

int	ft_atoi(const char *str)
{
	long	nbr;
	int		k;
	int		a;

	nbr = 0;
	k = 0;
	a = 1;
	while (str[k] == 32 || (str[k] > 8 && str[k] < 14))
		k++;
	if (str[k] == '+' || str[k] == '-')
	{
		if (str[k] == '-')
			a = -a;
		k++;
	}
	while (str[k] > 47 && str[k] < 58)
	{
		nbr = nbr * 10 + (str[k] - '0');
		if (nbr > 2147483647 && a == 1)
			return (-1);
		if (nbr > 2147483648 && a == -1)
			return (0);
		k++;
	}
	return (a * nbr);
}
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)))
	{	
		if (*(s1 + i) != *(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

static void	ft_putnbr_ll(long long n)
{
	if (n == -9223372036854775807)
	{
		write(1, "−9223372036854775807", 23);
	}
	else if (n < 0)
	{		
		write(1, "-", 1);
		ft_putnbr_ll(-n);
	}
	else if (n > 9)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
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
		ft_putnbr_ll(tt);
		ft_putchar(' ');
		ft_putnbr_ll(ph_id);
		ft_putchar(' ');
		write(1, str, len);
		ft_putchar('\n');
	}
	if (ft_strcmp(str, DIED))
		pthread_mutex_unlock(&data->table->message);
}