#include "philo.h"

t_bool	ft_isdigit(t_i32 c)
{
	return (c >= '0' && c <= '9');
}

t_i32	ft_stoi(const t_i8 *s)
{
	t_i32	sign;
	t_i32	res;

	sign = 1;
	res = 0;
	if ((*s == '-' || *s == '+') && ++s)
		if (*(s - 1) == '-')
			sign = -1;
	while (*s)
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

t_u64	ft_usleep(t_u64 us)
{
	static t_u64	target;
	static t_u64	cur;

	target = us + ft_utime();
	while (TRUE)
	{
		cur = ft_utime();
		if (target <= cur)
			break ;
		usleep(1);
	}
	return (cur - target);
}

t_u64	ft_utime()
{
	static t_timeval	cur;

	gettimeofday(&cur, NULL);
	return (cur.tv_sec * 1000000ull + cur.tv_usec);
}
