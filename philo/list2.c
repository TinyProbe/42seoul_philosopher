#include "philo.h"

void	*front(t_node *head)
{
	return (head->data);
}

void	*back(t_node *head)
{
	return (head->left->data);
}
