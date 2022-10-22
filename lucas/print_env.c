/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:33:13 by luserbu           #+#    #+#             */
/*   Updated: 2022/10/19 21:53:22 by luserbu          ###   ########.fr       */
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
	//free(data->fill_tab[i]);
	//free(data->var);
	data->fill_tab[i] = clean;
}

int check_quote(int i, char c, t_data *data)
{
	int j;

	j = ft_strlen(data->fill_tab[i]) - 1;
	if (data->fill_tab[i][0] == c)
		if (data->fill_tab[i][j] == c)
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

int	ft_str_path(char *big, char *little)
{
	int	i;

	i = 0;
	while (big[i] == little[i])
	{
		i++;
		if (little[i] == '\0' && big[i] == '=')
			return (1);
	}
	return (-1);
}

int	find_path(t_data *data)
{
	int i;
	int j;
	int len;
	char *no_dollar;

	if (!data->var || !data->var[1])
		return (1);
	no_dollar = ft_calloc(sizeof(char), ft_strlen(data->var) + 1);
	i = 1;
	j = 0;
	while (data->var[i])
		no_dollar[j++] = data->var[i++];
	no_dollar[i] = '\0';
	i = 0;
	len = ft_strlen(no_dollar);
	while (data->env[i])
	{
		if (ft_str_path(data->env[i], no_dollar) == 1)
		{
			data->clean_var  = malloc(sizeof(char) \
			* (ft_strlen(ft_strnstr(data->env[i], no_dollar, len)) + 1));
			data->clean_var = ft_strnstr(data->env[i], no_dollar, len);
			data->clean_var = clean_path(data);
			free(no_dollar);
			return (0);
		}
		i++;
	}
	// free(data->var);
	return (1);
}

int	chech_correct_path_arg(int i, char *str)
{
	if (str[i] == '_' \
	|| (str[i]  >= '0' && str[i]  <= '9') \
	|| (str[i]  >= 'a' && str[i]  <= 'z') \
	|| (str[i]  >= 'A' && str[i]  <= 'Z'))
		return (1);
	return (-1);
}

// void	remove_path(int i, int temp, t_data *data)
// {
// 	char *str;
// 	char *clean;
// 	int k;
// 	int j;


// 	if (check_quote(i, '\'', data) == -1)
// 		return ;
// 	str = data->fill_tab[i];
// 	clean = malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(data->var))

// }

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
			if (data->fill_tab[i][j] == '$' && check_quote(i, '\'', data) == 1)
			{
				temp = j;
				data->var = malloc(sizeof(char) * ft_strlen(data->fill_tab[i]) + 1);
				data->var[m++] = data->fill_tab[i][j++];
				while (chech_correct_path_arg(j, data->fill_tab[i]) == 1)
					data->var[m++] = data->fill_tab[i][j++];
				data->var[m] = '\0';
			}
			j++;
		}
		if (find_path(data) == 0)
			change_tab_path(i, temp, data);
		// else
		// 	remove_path(i, temp, data);
		i++;
	}
}
