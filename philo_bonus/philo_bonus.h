/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:36:51 by tkong             #+#    #+#             */
/*   Updated: 2022/12/21 05:37:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define MAX_PHILO	1000

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
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

typedef struct timeval		t_timeval;

# define TRUE	1
# define FALSE	0

typedef struct s_common
{
	t_u64	start;
	t_i32	nop;
	t_u64	life;
	t_u64	eat;
	t_u64	sleep;
	t_i32	limit;
}	t_common;

typedef struct s_db
{
	t_common	common;
	t_i32		num;
	t_i32		eat_cnt;
	t_u64		last_change;
	t_u64		last_eat;
	sem_t		*fork;
	sem_t		*fork_access;
	sem_t		*print;
	pid_t		pid[MAX_PHILO];
}	t_db;

t_bool	ft_isdigit(t_i32 c);
t_i32	ft_stoi(const t_i8 *s);
t_f64	ft_min(t_f64 a, t_f64 b);
t_f64	ft_max(t_f64 a, t_f64 b);
void	ft_usleep(t_u64 us);
t_u64	ft_utime(void);
t_u64	ft_utom(t_u64 us);
t_u64	ft_mtou(t_u64 ms);

t_i32	init(t_db *db, t_i32 ac, t_i8 **av);
void	exec(t_db *db);

void	schedule(t_db *db);
void	thinking(t_db *db);
void	eating(t_db *db);
void	sleeping(t_db *db);

void	loop(t_db *db);

#endif
