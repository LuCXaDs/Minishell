/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelnoff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:05:10 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/10/03 17:05:11 by gtelnoff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	main(void)
{
	unsigned char *cmd;
	unsigned char *buf;

	while (1)
	{
		cmd = readline("\033[1;31m🔥 MiniHell 🔥\033[0m > ");
		buf = getcwd(NULL, 4096);
		if (!strcmp(cmd, "pwd"))
			printf("%s\n", buf);
		if (!strcmp(cmd, "exit"))
		{
			free(cmd);
			return (0);
		}
		free(cmd);
	}

	return (0);
}
