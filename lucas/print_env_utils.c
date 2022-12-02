/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:33:13 by luserbu           #+#    #+#             */
/*   Updated: 2022/12/01 14:46:37 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [print_env_utils.c]
// int	ft_strlentab(char **tab);
// int	check_quote(int i, char c, t_data *data);
// char	*clean_path(char *path, t_data *data);
// int	ft_str_path(char *big, char *little);
// int	chech_correct_path_arg(int i, char *str);
// ------------------PROTOTYPE POUR LE ".h"------------------

int	ft_strlentab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	check_quote(int i, char c, t_data *data)
{
	int	j;

	j = ft_strlen(data->fill_tab[i]) - 1;
	if (data->fill_tab[i][0] == c)
		if (data->fill_tab[i][j] == c)
			return (-1);
	return (1);
}

char	*clean_path(char *path, t_data *data)
{
	int		i;
	int		j;
	char	*s;

	s = malloc(sizeof(char) * (ft_strlen(path) - ft_strlen(data->var) + 1));
	i = 0;
	j = ft_strlen(data->var);
	while (path[j])
		s[i++] = path[j++];
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

int	chech_correct_path_arg(int i, char *str)
{
	if (str[i] == '_' || (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a'
			&& str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		return (1);
	return (-1);
}
