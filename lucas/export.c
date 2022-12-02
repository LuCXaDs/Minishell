/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:51:01 by luserbu           #+#    #+#             */
/*   Updated: 2022/12/02 15:47:13 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [export.c]
// int	check_same_var(char *tab, t_data *data);
// char	*add_arg_to_var(int index, char *tab, t_data *data);
// int	loop_export(char **tab, int i, int j, t_data *data);
// void	export(char **tab, t_data *data);
// ------------------PROTOTYPE POUR LE ".h"------------------

int	check_same_var(char *tab, t_data *data)
{
	int		i;
	int		len;
	int		len_tmp;
	char	*var;
	char	*tmp;

	i = 0;
	len = strlen_stop(tab, '=');
	len_tmp = strlen_stop(tab, '+');
	if (len_tmp < len)
		len = len_tmp;
	var = ft_strdup(tab);
	var[len] = '\0';
	while (data->envp[i])
	{
		len = strlen_stop(data->envp[i], '=');
		tmp = ft_strdup(data->envp[i]);
		tmp[len] = '\0';
		if (ft_strcmp(tmp, var) == 0)
			return (free(tmp), free(var), i);
		free(tmp);
		i++;
	}
	free(var);
	return (-1);
}

char	*add_arg_to_var(int index, char *tab, t_data *data)
{
	int		i;
	int		j;
	char	*clean;

	clean = malloc(sizeof(char) * ft_strlen(tab));
	i = strlen_stop(tab, '=') + 1;
	j = 0;
	while (tab[i])
		clean[j++] = tab[i++];
	clean[j] = '\0';
	clean = ft_strjoin(data->envp[index], clean);
	return (clean);
}

int	loop_export(char **tab, int i, int j, t_data *data)
{
	int	index;
	char *tmp;

	index = check_same_var(tab[i], data);
	if (index != -1)
	{
		if (verif_var_character(tab[i]))
			tmp = add_arg_to_var(index, tab[i], data);
		else
			tmp = ft_strdup(tab[i]);
		free(data->envp[index]);
		data->envp[index] = tmp;
	}
	else
	{
		free(data->envp[data->len_envp + j]);
		if (verif_var_character(tab[i]))
			data->envp[data->len_envp + j++] = var_without_no_more(tab[i]);
		else
			data->envp[data->len_envp + j++] = ft_strdup(tab[i]);
	}
	return (j);
}

// void	export(char **tab, t_data *data)
// {
// 	int	i;
// 	int index;
// 	int	j;

// 	i = 1;
// 	j = 1;
// 	if (!tab[1])
// 	{
// 		print_export(data);
// 		return ;
// 	}
// 	while (tab[i])
// 	{
// 		index = check_same_var(tab[i], data);
// 		if (index != -1)
// 		{
// 			free(data->envp[index]);
// 			if (verif_var_character(tab[i]))
// 				data->envp[index] = add_arg_to_var(index, tab[i], data);
// 			else
// 				data->envp[index] = ft_strdup(tab[i]);
// 		}
// 		else
// 		{
// 			free(data->envp[data->len_envp + j]);
// 			if (verif_var_character(tab[i]))
// 				data->envp[data->len_envp + j++] = var_without_no_more(tab[i]);
// 			else
// 				data->envp[data->len_envp + j++] = ft_strdup(tab[i]);
// 		}
// 		i++;
// 	}
// 	data->envp[data->len_envp + j] = NULL;
// 	data->len_envp += j - 1;
// }

void	export(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (!tab[1])
	{
		print_export(data);
		return ;
	}
	while (tab[i])
	{
		j = loop_export(tab, i, j, data);
		i++;
	}
	data->envp[data->len_envp + j] = NULL;
	data->len_envp += j - 1;
}
