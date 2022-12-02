/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:13:06 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/12/02 15:47:11 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [echo.c]
// char	*ft_strjoin_free(char *s1, char *s2, int index);
// char	*double_tab_to_simple(char **array, int n);
// int	verif_arg_echo(char *tab)s;
// void	echo(char **tab);
// ------------------PROTOTYPE POUR LE ".h"------------------

char	*ft_strjoin_free(char *s1, char *s2, int index)
{
	int		i;
	int		j;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!dest)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[i] = s1[i];
	dest[i++] = ' ';
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	if (index > 2)
		free(s1);
	return (dest);
}

char	*double_tab_to_simple(char **array, int n)
{
	int		i;
	char	*str;

	i = 1 + n;
	while (array[i] != NULL)
	{
		if (i == 1 || n == 1)
		{
			str = array[i];
			i++;
		}
		else
		{
			str = ft_strjoin_free(str, array[i], i);
			i++;
		}
	}
	return (str);
}

int	verif_arg_echo(char *tab)
{
	int	i;

	if (tab[0] != '-' || tab[1] == '\0')
		return (0);
	i = 1;
	while (tab[i])
	{
		if (tab[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo(char **tab)
{
	int		n;
	char	*str;

	n = verif_arg_echo(tab[1]);
	str = double_tab_to_simple(tab, n);
	if (n == 1)
		printf("%s", str);
	else
		printf("%s\n", str);
	printf("$\n");
}
