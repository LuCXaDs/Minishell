/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:05:10 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/10/11 16:58:17 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_struct_value(t_data *data)
{
	data->check_tab.k_s_q = 0;
	data->check_tab.k_d_q = 0;
	data->check_tab.simple_quote = 0;
	data->check_tab.double_quote = 0;
}

int	main(void)
{
	t_data data;
	unsigned char *buf;

	while (1)
	{
		data.line = readline("\033[1;31m🔥 MiniHell 🔥\033[0m > ");
		add_history(data.line);
		buf = getcwd(NULL, 4096);
		if (!strcmp(data.line, "pwd"))
			printf("%s\n", buf);
		if (!strcmp(data.line, "exit"))
		{
			free(data.line);
			return (0);
		}
		if (!strcmp(data.line, "\"lol\""))
		{
			int i = 0;
			init_struct_value(&data);
			fill_tab_arg(&data);
			while (data.fill_tab[i])
			{
				printf("%s\n", data.fill_tab[i]);
				i++;
			}
		}
		free(data.line);
	}

	return (0);
}
