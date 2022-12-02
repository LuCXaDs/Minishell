/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:51:01 by luserbu           #+#    #+#             */
/*   Updated: 2022/12/02 15:47:12 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [exit.c]
// int	verif_letter(char *tab);
// int	loop_strdiff(int i, int j, char *s1, char *s2);
// int	ft_strdiff(char *s1, char *s2);
// int	exit_lol(char **tab);
// ------------------PROTOTYPE POUR LE ".h"------------------

int	verif_letter(char *tab)
{
	int	i;

	i = 0;
	if (tab[0] == '-')
		i = 1;
	while (tab[i])
	{
		if (tab[i] >= '0' && tab[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	loop_strdiff(int i, int j, char *s1, char *s2)
{
	while (s1[i] || s2[i + j])
	{
		if (s1[i] == s2[i + j])
			i++;
		else if (s1[i] > s2[i + j])
			return (1);
		else
			return (0);
	}
	return (1);
}

int	ft_strdiff(char *s1, char *s2)
{
	int	i;
	int	j;
	int	len1;
	int	len2;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (s2[0] == '-')
	{
		len2 -= 1;
		j += 1;
	}
	if (len1 > len2)
		return (1);
	if (len1 < len2)
		return (0);
	if (!loop_strdiff(i, j, s1, s2))
		return (0);
	return (1);
}

int	exit_lol(char **tab)
{
	unsigned char   c;

	if (!tab[1])
		printf("GOOD");
	else if (!verif_letter(tab[1]))
		printf("bash: exit: %s: numeric argument required\n", tab[1]);
	else if (tab[2])
		printf("bash: exit: too many arguments\n");
	else if (!ft_strdiff("9223372036854775807", tab[1]))
		printf("bash: exit: %s: numeric  required\n", tab[1]);
	c = ft_atoi(tab[1]);
	printf("%d\n", c);
	return (c);
}
