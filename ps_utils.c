/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:59:33 by toantune          #+#    #+#             */
/*   Updated: 2024/04/29 20:54:51 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./tests/test_ps_utils.c"

long int	*convert_argv(int size, char **argv)
{
	long int	*arr;
	int			i;

	if (!size || !argv)
		error((void **)argv, size);
	arr = malloc(sizeof(long int) * (size));
	if (!arr)
		error((void **)&arr, 1);
	i = 0;
	while (argv[i])
	{
		arr[i] = ft_atol(argv[i]);
		i++;
	}
	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (arr);
}

int	*map_index(long int *arr, int size)
{
	int		*index;
	int		i;
	int		j;

	index = malloc(sizeof(int) * size);
	if (!index)
		return (0);
	i = 0;
	while (i < size)
	{
		index[i] = 0;
		j = 0;
		while (j < size)
		{
			if ((int)arr[j] < (int)arr[i])
				index[i]++;
			j++;
		}
		i++;
	}
	return (index);
}

int	get_argv_size(char **arg_vec)
{
	int	size;

	size = 0;
	while (arg_vec[size] != NULL)
		size++;
	return (size);
}

int	get_stck_max(t_clist *stack)
{
	t_clist	*curr;
	int		max;

	max = 0;
	curr = stack;
	while (1)
	{
		if (curr->index > max)
			max = curr->index;
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (max);
}

int	get_stck_min(t_clist *stack)
{
	t_clist	*curr;
	int		min;

	min = get_stck_max(stack);
	curr = stack;
	while (1)
	{
		if (curr->index < min)
			min = curr->index;
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (min);
}
