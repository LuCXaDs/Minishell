/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:33:13 by luserbu           #+#    #+#             */
/*   Updated: 2022/12/02 15:47:18 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [print_env.c]
// void	change_tab_path(int i, int temp, t_data *data);
// int	loop_find_path(char *no_dollar, t_data *data);
// int	find_path(int index_i, int index_j, t_data *data);
// int	loop_search_path(int i, int j, int temp, t_data *data);
// void	search_path(t_data *data);
// ------------------PROTOTYPE POUR LE ".h"------------------

void	change_tab_path(int i, int temp, t_data *data)
{
	char	*str;
	char	*clean;
	int		k;
	int		j;

	str = data->fill_tab[i];
	k = 0;
	j = 0;
	clean = malloc(sizeof(char *) * ((ft_strlen(data->clean_var)
					+ ft_strlen(data->fill_tab[i]) - ft_strlen(data->var))));
	while (k < temp)
	{
		clean[k] = str[k];
		k++;
	}
	while (data->clean_var[j])
		clean[k++] = data->clean_var[j++];
	free(data->clean_var);
	j = temp + ft_strlen(data->var);
	if (str[j] == '\'' || str[j] == '\"')
		clean[k++] = str[j++];
	clean[k] = '\0';
	free(data->fill_tab[i]);
	data->fill_tab[i] = clean;
	free(data->var);
}

int	loop_find_path(char *no_dollar, t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (ft_str_path(data->envp[i], no_dollar) == 1)
		{
			data->clean_var = clean_path(data->envp[i], data);
			free(no_dollar);
			return (1);
		}
		i++;
	}
	return (0);
}

int	find_path(int index_i, int index_j, t_data *data)
{
	int		i;
	int		j;
	char	*no_dollar;

	if (!data->var || !data->var[1])
		return (0);
	no_dollar = ft_calloc(sizeof(char), ft_strlen(data->var) + 1);
	i = 1;
	j = 0;
	while (data->var[i])
		no_dollar[j++] = data->var[i++];
	no_dollar[i] = '\0';
	if (loop_find_path(no_dollar, data))
		return (1);
	free(no_dollar);
	data->fill_tab[index_i][index_j] = '\0';
	free(data->var);
	return (0);
}

int	loop_search_path(int i, int j, int temp, t_data *data)
{
	int	m;

	m = 0;
	if (data->fill_tab[i][j] == '$' && check_quote(i, '\'', data) == 1)
	{
		temp = j;
		data->var = malloc(sizeof(char) * ft_strlen(data->fill_tab[i]) + 1);
		data->var[m++] = data->fill_tab[i][j++];
		while (chech_correct_path_arg(j, data->fill_tab[i]) == 1)
			data->var[m++] = data->fill_tab[i][j++];
		data->var[m] = '\0';
	}
	return (temp);

}

void	search_path(t_data *data)
{
	int	i;
	int j;
	int temp;

	i = 0;
	temp = 0;
	while (data->fill_tab[i])
	{
		j = 0;
		while (data->fill_tab[i][j])
		{
			temp = loop_search_path(i, j, temp, data);
			if (data->fill_tab[i][j])
				j++;
		}
		if (find_path(i, temp, data))
			change_tab_path(i, temp, data);
		i++;
	}
}
