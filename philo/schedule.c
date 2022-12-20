#include "philo.h"

static void		schedule_loop(t_philo *philo);
static t_i32	die_check(t_philo *philo);

void	*schedule(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *) ptr;
	while (TRUE)
	{
		pthread_mutex_lock(philo->created_mutex);
		if (*(philo->created) == philo->common.nop)
		{
			pthread_mutex_unlock(philo->created_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->created_mutex);
	}
	pthread_mutex_lock(philo->last_eat_mutex);
	philo->common.start = ft_utime();
	philo->last_change = philo->common.start;
	*(philo->last_eat) = philo->common.start;
	pthread_mutex_unlock(philo->last_eat_mutex);
	if (!(philo->num & 1))
		usleep(ft_usync(10000));
	else if (philo->num == philo->common.nop)
		usleep(ft_usync(20000));
	schedule_loop(philo);
	return (NULL);
}

static void	schedule_loop(t_philo *philo)
{
	if (philo->common.nop == 1)
		return ;
	while (TRUE)
	{
		thinking(philo);
		if (die_check(philo))
			break ;
		eating(philo);
		if (die_check(philo))
			break ;
		sleeping(philo);
		if (die_check(philo))
			break ;
	}
	if (philo->state == S_EAT)
	{
		pthread_mutex_unlock(philo->left_mutex);
		pthread_mutex_unlock(philo->right_mutex);
	}
}

static t_i32	die_check(t_philo *philo)
{
	pthread_mutex_lock(philo->end_mutex);
	if (*(philo->end) < 0 || philo->eat_cnt == philo->common.limit)
	{
		++*(philo->end);
		pthread_mutex_unlock(philo->end_mutex);
		return (-1);
	}
	pthread_mutex_unlock(philo->end_mutex);
	return (0);
}
