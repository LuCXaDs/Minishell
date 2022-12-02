/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:51:01 by luserbu           #+#    #+#             */
/*   Updated: 2022/12/02 15:47:13 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [export_utils.c]
// int	verif_var_character(char *tab);
// char	*var_without_no_more(char *tab);
// ------------------PROTOTYPE POUR LE ".h"------------------

int	verif_var_character(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i + 1] && tab[i] == '+' && tab[i + 1] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	*var_without_no_more(char *tab)
{
	int		i;
	int		j;
	char	*clean_tab;

	i = 0;
	j = 0;
	clean_tab = malloc(sizeof(char) * ft_strlen(tab));
	while (tab[i])
	{
		if (tab[i] != '+')
			clean_tab[j++] = tab[i];
		i++;
	}
	clean_tab[j] = '\0';
	return (clean_tab);
}
