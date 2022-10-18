/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:33:13 by luserbu           #+#    #+#             */
/*   Updated: 2022/10/17 19:45:54 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_tab_path(int i, int temp, t_data *data)
{
	char *str;
	char *clean;
	int k;
	int j;

	str = data->fill_tab[i];
	k = 0;
	j = temp;
	clean = malloc (sizeof(char *)  * ((ft_strlen(data->clean_var) \
	+ ft_strlen(data->fill_tab[i]) \
	- ft_strlen(data->var))));
	while (k < temp)
	{
		clean[k] = str[k];
		k++;
	}
	while (data->clean_var[j])
		clean[k++] = data->clean_var[j++];
	j = temp + ft_strlen(data->var);
	while (str[j])
		clean[k++] = str[j++];
	clean[k] = '\0';
	// free(data->fill_tab[i]);
	// free(data->var);
	data->fill_tab[i] = clean;
}

int check_simple_quote(int i, t_data *data)
{
	int j;

	j = ft_strlen(data->fill_tab[i]) - 1;
	if (data->fill_tab[i][0] == '\'')
		if (data->fill_tab[i][j] == '\'')
			return (-1);
	return (1);
}

char	*clean_path(t_data *data)
{
	int		i;
	int		j;
	char	*s;

	s = malloc(sizeof(char) * (ft_strlen(data->clean_var) - ft_strlen(data->var) + 1));
	i = 0;
	j = ft_strlen(data->var);
	while (data->clean_var[j])
		s[i++] = data->clean_var[j++];
	s[i] = '\0';
	return (s);
}

int	find_path(t_data *data)
{
	int i;
	int j;
	int len;
	char *str;

	if (!data->var || !data->var[1])
		return (1);
	i = 1;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen(data->var) + 1);
	while (data->var[i])
		str[j++] = data->var[i++];
	str[i] = '\0';
	i = 0;
	len = ft_strlen(str);
	while (data->env[i])
	{
		if (ft_strnstr(data->env[i], str, len) != NULL)
		{
			data->clean_var  = ft_strnstr(data->env[i], str, len);
			data->clean_var = clean_path(data);
			free(str);
			return (0);
		}
		i++;
	}
	// free(data->var);
	return (1);
}

void	search_path(t_data *data)
{
	int i;
	int j;
	int	m;
	int temp;

	i = 0;
	m = 0;
	temp = 0;
	while (data->fill_tab[i])
	{
		j = 0;
		while (data->fill_tab[i][j])
		{
			if (data->fill_tab[i][j] == '$' && check_simple_quote(i, data) == 1)
			{
				temp = j;
				data->var = malloc(sizeof(char) * ft_strlen(data->fill_tab[i]));
				data->var[m++] = data->fill_tab[i][j++];
				while(data->fill_tab[i][j] == '_' || (data->fill_tab[i][j] >= '0' \
				&& data->fill_tab[i][j] <= '9') \
				|| (data->fill_tab[i][j] >= 'a' && data->fill_tab[i][j] <= 'z') \
				|| (data->fill_tab[i][j] >= 'A' && data->fill_tab[i][j] <= 'Z'))
					data->var[m++] = data->fill_tab[i][j++];
				data->var[m] = '\0';
			}
			j++;
		}
		if (find_path(data) == 0)
			change_tab_path(i, temp, data);
		printf("{%s}\n", data->fill_tab[i]);
		i++;
	}
}
