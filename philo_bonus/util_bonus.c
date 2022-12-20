/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:37:03 by tkong             #+#    #+#             */
/*   Updated: 2022/12/21 05:37:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

t_f64	ft_min(t_f64 a, t_f64 b)
{
	if (a < b)
		return (a);
	return (b);
}

t_f64	ft_max(t_f64 a, t_f64 b)
{
	if (a > b)
		return (a);
	return (b);
}
