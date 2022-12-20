#include "philo.h"

static void	take_left(t_philo *philo);
static void	take_right(t_philo *philo);

void	thinking(t_philo *philo)
{
	take_left(philo);
	take_right(philo);
	shift_state(philo);
	pthread_mutex_lock(philo->end_mutex);
	if (*(philo->end) >= 0)
		printf("%llu %d is eating\n",
			ft_utom(philo->last_change - philo->common.start), philo->num);
	pthread_mutex_unlock(philo->end_mutex);
}

static void	take_left(t_philo *philo)
{
	pthread_mutex_lock(philo->left_mutex);
	pthread_mutex_lock(philo->end_mutex);
	if (*(philo->end) >= 0)
		printf("%llu %d has taken a fork\n",
			ft_utom(ft_utime() - philo->common.start), philo->num);
	pthread_mutex_unlock(philo->end_mutex);
}

static void	take_right(t_philo *philo)
{
	pthread_mutex_lock(philo->right_mutex);
	pthread_mutex_lock(philo->end_mutex);
	if (*(philo->end) >= 0)
		printf("%llu %d has taken a fork\n",
			ft_utom(ft_utime() - philo->common.start), philo->num);
	pthread_mutex_unlock(philo->end_mutex);
}

void	eating(t_philo *philo)
{
	ft_usleep(philo->common.eat);
	shift_state(philo);
	pthread_mutex_lock(philo->end_mutex);
	if (*(philo->end) >= 0)
		printf("%llu %d is sleeping\n",
			ft_utom(philo->last_change - philo->common.start), philo->num);
	pthread_mutex_unlock(philo->end_mutex);
	pthread_mutex_unlock(philo->left_mutex);
	pthread_mutex_unlock(philo->right_mutex);
}

void	sleeping(t_philo *philo)
{
	ft_usleep(philo->common.sleep);
	shift_state(philo);
	pthread_mutex_lock(philo->end_mutex);
	if (*(philo->end) >= 0)
		printf("%llu %d is thinking\n",
			ft_utom(philo->last_change - philo->common.start), philo->num);
	pthread_mutex_unlock(philo->end_mutex);
}
