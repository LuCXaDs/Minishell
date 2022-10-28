/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:05:10 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/10/24 22:42:04 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_struct_value(t_data *data)
{
	data->var = NULL;
	data->clean_var = NULL;
	data->check_tab.j = 0;
	data->check_tab.i = 0;
	data->check_tab.len = 0;
}

int	main(int ac, char **av, char **env)
{
	t_data data;

	(void)ac;
	data.envp = env;
	data.line = (unsigned char *)av[1];
	printf("%s\n\n", data.line);
	init_struct_value(&data);
	data.line = first_parser(data.line);
	fill_tab_arg(&data);
	int i;
	//search_path(&data);
	export(&data);
	i = 0;
	while (data.fill_tab[i])
	{
		printf("%s\n", data.fill_tab[i]);
		free(data.fill_tab[i]);
		i++;
	}
	while (data.env[i])
	{
		free(data.env[i]);
		i++;
	}
//	free(data.line);
	free(data.fill_tab);
	free(data.env);
	return (0);
}
