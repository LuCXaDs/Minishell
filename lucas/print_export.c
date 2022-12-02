/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:05:52 by luserbu           #+#    #+#             */
/*   Updated: 2022/12/02 15:46:58 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [print_export.c]
// char	*add_quote2(char *tmp, int count, int i, int j);
// char	*add_quote(char *str);
// void	add_argument_into_export(t_data *data);
// void	sort_loop(t_data *data);
// void	print_export(t_data *data);
// ------------------PROTOTYPE POUR LE ".h"------------------

char	*add_quote2(char *tmp, int count, int i, int j)
{
	if (count == 1)
	{
		tmp[j++] = '\"';
		tmp[j] = '\0';
	}
	else
		tmp[j] = '\0';
	i = ft_strlen(tmp);
	if (tmp[i] && tmp[i - 1])
	{
		if (tmp[i] == '\"' && tmp[i - 1] == '=')
		{
			tmp[i + 1] = '\"';
			tmp[i + 2] = '\0';
		}
	}
	return (tmp);
}

char	*add_quote(char *str)
{
	int		i;
	int		j;
	int		len;
	int		count;
	char	*tmp;

	j = 0;
	i = 0;
	count = 0;
	tmp = malloc(sizeof(char) * ft_strlen(str) + 4);
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == '=' && count == 0)
		{
			tmp[j++] = '=';
			i++;
			tmp[j++] = '\"';
			count = 1;
		}
		tmp[j++] = str[i++];
	}
	free(str);
	return (add_quote2(tmp, count, i, j));
}

void	add_argument_into_export(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->env[i])
	{
		tmp = ft_strjoin("declare -x ", data->env[i]);
		tmp = add_quote(tmp);
		free(data->env[i]);
		data->env[i] = tmp;
		printf("%s\n", data->env[i]);
		free(data->env[i]);
		i++;
	}
	free(data->env);
}

void	sort_loop(t_data *data)
{
	int		i;
	int		j;
	char	*temp;

	j = 1;
	i = 0;
	while (data->env[j])
	{
		i = 0;
		while (data->env[i])
		{
			if (ft_strcmp(data->env[i], data->env[j]) > 0)
			{
				temp = data->env[i];
				data->env[i] = data->env[j];
				data->env[j] = temp;
			}
			i++;
		}
		j++;
	}
}

void	print_export(t_data *data)
{
	int	i;

	i = 0;
	data->env = malloc(sizeof(char *) * 4096);
	while (data->envp[i])
	{
		data->env[i] = ft_substr(data->envp[i], 0, ft_strlen(data->envp[i]));
		i++;
	}
	data->env[i] = NULL;
	sort_loop(data);
	add_argument_into_export(data);
}
