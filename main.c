/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:05:10 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/10/04 23:32:09 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(void)
{
	t_data data;
	unsigned char *buf;

	while (1)
	{
		data.line = readline("\033[1;31m🔥 MiniHell 🔥\033[0m > ");
		buf = getcwd(NULL, 4096);
		if (!strcmp(data.line, "pwd"))
			printf("%s\n", buf);
		if (!strcmp(data.line, "exit"))
		{
			free(data.line);
			return (0);
		}
		if (!strcmp(data.line, "jesuis"))
		{
			int i = 0;
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
