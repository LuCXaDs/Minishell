/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:51:01 by luserbu           #+#    #+#             */
/*   Updated: 2022/12/13 15:01:30 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [parsing.c]
// void	init_struct_value(t_parse *parse);
// void	malloc_envp(char **env, t_parse *parse);
// char **parsing(t_parse *parse);
// ------------------PROTOTYPE POUR LE ".h"------------------

void	init_struct_value(t_parse *parse)
{
	parse->var = NULL;
	parse->cmpt_line = 0;
	parse->clean_var = NULL;
	parse->index.j = 0;
	parse->index.i = 0;
	parse->index.len = 0;
	parse->fill_tab = NULL;
}

void	malloc_envp(char **env, t_parse *parse)
{
	int	i;

	i = 0;
	parse->envp = ft_calloc(sizeof(char *), 4096);
	while (env[i])
	{
		parse->envp[i] = ft_substr(env[i], 0, ft_strlen(env[i]));
		i++;
	}
	parse->len_envp = i - 1;
	parse->envp[i] = NULL;
}

char	**parsing(t_parse *parse)
{
	if (first_parser(parse))
	{
		fill_tab_arg(parse);
		search_path(parse);
		ft_free(parse, FALSE);
		return (parse->fill_tab);
	}
	else
		ft_free(parse, TRUE);
	return (NULL);
}
