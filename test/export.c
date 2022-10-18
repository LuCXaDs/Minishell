/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:05:52 by luserbu           #+#    #+#             */
/*   Updated: 2022/10/18 14:59:20 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	strlen_stop(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
	}
	return (i);
}
// if (data->env[j][i] > data->env[j][i + 1]
// && data->env[j][i + 1] && data->env[j][i])
// {
// 	tmp = data->env[j];
// 	data->env[j] = data->env[j + 1];
// 	data->env[j + 1] = tmp;
// }

void	sort_list(t_data *data)
{
	char *tmp;
	int len;
	int i;
	int j;

	i = 1;
	printf(data->env[0]);
	len = strlen_stop(data->env[0], '=');
	while (data->env[i])
	{
		if (len < strlen_stop(data->env[i], '='))
			len = strlen_stop(data->env[i], '=');
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = 0;
		while (data->env[j])
		{
			j = 0;
			while (data->env[j][i] > data->env[j + 1][i] \
			&& data->env[j][i] && data->env[j + 1][i])
			{
				tmp = data->env[j];
				data->env[j] = data->env[j + 1];
				data->env[j + 1] = tmp;
				j++;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
}
void	export(t_data *data)
{
	// data->env = data->env;
	sort_list(data);
}
