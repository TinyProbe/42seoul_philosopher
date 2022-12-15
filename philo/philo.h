/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:10:31 by tkong             #+#    #+#             */
/*   Updated: 2022/12/08 19:11:54 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_THREAD	1000

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef float				t_f32;
typedef double				t_f64;
typedef char				t_i8;
typedef short				t_i16;
typedef int					t_i32;
typedef long long			t_i64;
typedef long int			t_isize;
typedef unsigned char		t_u8;
typedef unsigned short		t_u16;
typedef unsigned int		t_u32;
typedef unsigned long long	t_u64;
typedef unsigned long int	t_usize;
typedef char				t_bool;

# define TRUE	1
# define FALSE	0

enum e_state
{
	S_THINK = 0,
	S_EAT = 1,
	S_SLEEP = 2,
};

enum e_event
{
	E_LFORK = 0,
	E_RFORK = 1,
	E_EAT = 2,
	E_THINK = 3,
	E_SLEEP = 4,
	E_DIE = 5,
};

typedef struct timeval	t_timeval;

typedef struct s_node
{
	struct s_node	*left;
	struct s_node	*right;
	void			*data;
}	t_node;

typedef struct s_event
{
	t_u64	time;
	t_i32	philo_num;
	t_i32	event;
}	t_event;

typedef struct s_common
{
	t_u64			start_time;
	t_i32			nop;
	t_u64			life;
	t_u64			eat;
	t_u64			sleep;
	t_i32			limit;
	t_node			*event;
	t_i32			event_cnt;
	pthread_mutex_t	event_mutex;
}	t_common;

typedef struct s_philo
{
	pthread_t		thread;
	t_i32			num;
	t_i32			state;
	t_u64			last_change;
	t_u64			last_eat;
	t_bool			*left_fork;
	t_bool			*right_fork;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;
	t_common		*common;
}	t_philo;

typedef struct s_db
{
	t_philo			philo[MAX_THREAD];
	t_bool			fork[MAX_THREAD];
	pthread_mutex_t	fork_mutex[MAX_THREAD];
	t_i32			eat_cnt[MAX_THREAD];
	t_common		common;
}	t_db;

t_bool	ft_isdigit(t_i32 c);
t_i32	ft_stoi(const t_i8 *s);
t_u64	ft_usleep(t_u64 us);
t_u64	ft_utime();
t_u64	ft_utom(t_u64 us);
t_u64	ft_mtou(t_u64 ms);

void	push_front(t_node **head, void *data);
void	push_back(t_node **head, void *data);
void	*pop_front(t_node **head);
void	*pop_back(t_node **head);
void	*front(t_node *head);
void	*back(t_node *head);

t_i32	init(t_db *db, t_i32 ac, t_i8 **av);
void	exec(t_db *db);

void	*schedule(void *db);
void	loop(t_db *db);

#endif
