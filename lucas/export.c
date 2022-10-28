/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:05:52 by luserbu           #+#    #+#             */
/*   Updated: 2022/10/25 17:34:58 by luserbu          ###   ########.fr       */
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
		i++;
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

#include <string.h>

char	*add_quote(char *str)
{
	int i;
	int j;
	char	*tmp;


	j = 0;
	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(str) + 4);
	while (str[i])
	{
		if (str[i] && str[i] == '=')
		{
			tmp[j++] = '=';
			i++;
			tmp[j++] = '\"';
		}
		tmp[j++] = str[i++];
	}
	tmp[j++] = '\"';
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

void	add_argument_into_export(t_data *data)
{
	int i;
	char *tmp;

	i = 0;
	while (data->env[i])
	{
		tmp = ft_strjoin("declare -x ", data->env[i]);
		tmp = add_quote(tmp);
		free(data->env[i]);
		data->env[i] = tmp;
		// printf("%s\n", data->env[i]);
		i++;
	}
}

void	sort_list(t_data *data)
{
	int i;
	int j;
	int k;
	int sort;
	int verif_sort;
	int cmpt;
	int len;
	// int len_var;
	char *tmp;

	i = 0;
	len = strlen_stop(data->env[0], '=');
	while (data->env[i])
	{
		if (len < strlen_stop(data->env[i], '='))
		{
			len = strlen_stop(data->env[i], '=');
		}
		i++;
	}
	verif_sort = i - 1;
	i = 0;
	cmpt = 1;
	while (i < len)
	{
		k = 0;
		while (data->env[k])
		{
			j = 0;
			sort = 0;
			while (data->env[j] && data->env[j + 1])
			{
				// printf("%s\n", data->env[j]);
				if (strlen_stop(data->env[j], '=') > i \
				&& data->env[j][i] > data->env[j + 1][i])
				{
					if (i > 0)
						cmpt = strncmp(data->env[j], data->env[j + 1], i);
					if (i == 0)
					{
						tmp = data->env[j];
						data->env[j] = data->env[j + 1];
						data->env[j + 1] = tmp;
					}
					if (cmpt == 0)
					{
						tmp = data->env[j];
						data->env[j] = data->env[j + 1];
						data->env[j + 1] = tmp;
					}
					j++;
			}
				else
				{
					j++;
					sort++;
				}
			}
			if (verif_sort == sort)
				break;
			k++;
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


	// while (i < 15)
	// {
	// 	k = 0;
	// 	while (data->env[k])
	// 	{
	// 		j = 0;
	// 		while (data->env[j] && data->env[j + 1])
	// 		{
	// 			// printf("%s\n", data->env[j]);
	// 			if (strlen_stop(data->env[j], '=') >= i
	// 			&& data->env[j][i] > data->env[j + 1][i])
	// 			{
	// 				if (data->env[j][i] && data->env[j + 1][i])
	// 				{
	// 					if (i > 0)
	// 						cmpt = ft_strcmp(ft_substr(data->env[j], 0, i),
	// 						ft_substr(data->env[j + 1], 0, i));
	// 					if (i == 0)
	// 					{
	// 						tmp = data->env[j];
	// 						data->env[j] = data->env[j + 1];
	// 						data->env[j + 1] = tmp;
	// 					}
	// 					if (cmpt == 0)
	// 					{
	// 						tmp = data->env[j];
	// 						data->env[j] = data->env[j + 1];
	// 						data->env[j + 1] = tmp;
	// 					}
	// 					j++;
	// 				}
	// 			}
	// 			else
	// 				j++;
	// 		}
	// 		k++;
	// 	}
	// 	i++;
	// }
// 	i = 0;
// 	while (data->env[i])
// 	{
// 		printf("%s\n", data->env[i]);
// 		i++;
// 	}
// }

void	malloc_env(t_data *data)
{
	int i;

	data->env = malloc(sizeof(char *) * 4096);
	i = 0;
	while (data->envp[i])
	{
		data->env[i] = ft_substr(data->envp[i], 0, ft_strlen(data->envp[i]));
		// printf("%s\n", data->env[i]);
		i++;
	}
	printf("\n\n");
	data->env[i] = NULL;
}

void	export(t_data *data)
{
	// data->env = data->env;
	malloc_env(data);
	sort_list(data);
	add_argument_into_export(data);
}
