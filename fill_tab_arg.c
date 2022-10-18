/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:33:18 by luserbu           #+#    #+#             */
/*   Updated: 2022/10/11 16:34:30 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_words(char *s)
{
	int	i;
	int	cmpt;
	char c;

	c = ' ';
	i = 0;
	if (s[i] == c || s[i] == 0)
		cmpt = 0;
	else
		cmpt = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			cmpt++;
		i++;
	}
	return (cmpt + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (dest[i])
		i++;
	while (src[m])
		dest[i++] = src[m++];
	dest[i] = '\0';
	return (dest);
}

// int	fill_character_into_tab(int i, int j, t_data *data)
// {
// 	int k;

// 	k = i;
// 	while (data->line[i])
// 	{
// 		if (data->line[i] == ' ')
// 			break;
// 		i++;
// 	}
// 	data->fill_tab[j] = ft_substr(data->line, k, i);
// 	data->fill_tab[j + 1] = NULL;
// 	// while (data->line[i] == ' ')
// 	// 	i++;
// 	return (i);
// }

// Count, how many character that you choice in variable 'c'
int	ft_strnb(char *str, char c)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_strdel(char *str, char c, int nb)
{
	char *final;
	int quote;
	int i;
	int	j;

	i = 0;
	j = 0;
	quote = 0;
	while (str[i])
	{
		if (nb > quote)
			if (str[i] == c)
			{
				quote++;
				i++;
			}
		final[j++] = str[i++];
	}
	final[j] = '\0';
	final = malloc(sizeof(char) * ft_strlen(final) + 1);
	free(str);
	return (final);

}

// void	loop_check_tab(int i, int j, t_data *data)
// /* k_s_q ; k : is an index ; s_q = simpe_quote*/
// /* k_s_q ; k : is an index ; s_d = double_quote*/
// {
// 	char *str;

// 	if (data->fill_tab[i][j] == '\'')
// 		data->check_tab.simple_quote++;
// 	if (data->fill_tab[i][j] == '\"')
// 		data->check_tab.double_quote++;
// }

void	check_tab(t_data *data)
{
	int i;

	i = 0;
	while (data->fill_tab[i])
	{
		data->check_tab.simple_quote = ft_strnb(data->fill_tab[i], '\'');
		data->check_tab.double_quote = ft_strnb(data->fill_tab[i], '\"');
		if (data->check_tab.double_quote >= 2)
		{
			if (data->check_tab.double_quote % 2 == 0)
				data->fill_tab[i] = ft_strdel(data->fill_tab[i], '\"', data->check_tab.double_quote);
			else
				data->fill_tab[i] = ft_strdel(data->fill_tab[i], '\"', data->check_tab.double_quote - 1);
		}
		i++;
	}
}

void	fill_tab_arg(t_data *data)
{
	data->fill_tab = ft_split(data->line, ' ');
	check_tab(data);
//	check_tab
	// int i;
	// int j;
	// int k;

	// i = 0;
	// j = 0;
	// data->fill_tab = malloc(sizeof(char *) * ft_words(data->line) + 1);
	// while (data->line[i] == ' ')
	// 	i++;
	// k = i;
	// while(data->line[i])
	// {
	// 	// if (data->line[i] == '\'')
	// 	// 	;
	// 	// else if (data->line[i] == '\"')
	// 	// 	;
	// 	if (data->line[i] >= '!' && data->line[i] <= '~')
	// 	{
	// 		i = fill_character_into_tab(i, j, data);
	// 		j++;
	// 	}
	// 	if (data->line[i] == ' ')
	// 		while (data->line[i] == ' ')
	// 			i++;
	// 	else
	// 		i++;
	// }
}

// int	data->check_tab.simple_quote(t_data *data, int index_i, int index_j);

// void	fill_tab_arg(t_data *data)
// {
// 	int i;
// 	int j;
// 	int k;

// 	i = 0;
// 	j = 0;
// 	data->fill_tab = malloc(sizeof(char *) * ft_words(data->line) + 1);
// 	while (data->line[i] == ' ')
// 		i++;
// 	k = i;
// 	while(data->line[i])
// 	{
// 		if (data->line[i] == ' ' || data->line[i + 1] == '\0');
// 		{
// 			data->fill_tab[j] = ft_substr(data->line, k, (i - 1));
// 			while (data->line[i] == ' ' && data->line[i + 1] == ' ')
// 				i++;
// 			k = i + 1;
// 			j++;
// 		}
// 		if (data->line[i] == '\'')
// 		{
// 			i = data->check_tab.simple_quote(data, i, j);
// 			while (data->line[i] == ' ' && data->line[i + 1] == ' ')
// 				i++;
// 			j++;
// 			k = i + 1;
// 		}
// 		i++;
// 	}
// }

// int	data->check_tab.simple_quote(t_data *data, int index_i, int index_j)
// {
// 	int i;
// 	int j;
// 	int fst_index;
// 	int snd_index;

// 	i = -1;
// 	while (data->line[i])
// 	{
// 		i++;
// 		if (data->line[i] == '\'')
// 		{
// 			fst_index = i;
// 			j = i;
// 			while (data->line[j] != '\'')
// 			{
// 				j++;
// 				if (data->line[j] == '\0')
// 					break;
// 				else if (data->line[j] == '\'' && data->line[j + 1] != '\'')
// 				{
// 					snd_index = j;
// 					data->fill_tab[index_j] = ft_substr(data->line, fst_index, snd_index);
// 					return (snd_index);
// 				}
// 			}
// 		}
// 	}
// 	return (index_i);
// }

// int	data->check_tab.simple_quote(t_data *data, int index_i, int index_j);

// void	fill_tab_arg(t_data *data)
// {
// 	int i;
// 	int j;
// 	int k;

// 	i = 0;
// 	j = 0;
// 	data->fill_tab = malloc(sizeof(char *) * ft_words(data->line) + 1);
// 	while (data->line[i] == ' ')
// 		i++;
// 	k = i;
// 	while(data->line[i])
// 	{
// 		if (data->line[i] == ' ' || data->line[i + 1] == '\0');
// 		{
// 			data->fill_tab[j] = ft_substr(data->line, k, (i - 1));
// 			j++;
// 			while (data->line[i] == ' ' && data->line[i + 1] == ' ')
// 				i++;
// 			k = i + 1;
// 		}
// 		if (data->line[i] == '\'')
// 		{
// 			i = data->check_tab.simple_quote(data, i, j);
// 			while (data->line[i] == ' ' && data->line[i + 1] == ' ')
// 				i++;
// 			j++;
// 			k = i + 1;
// 		}
// 		i++;
// 	}
// }

// int	data->check_tab.simple_quote(t_data *data, int index_i, int index_j)
// {
// 	int i;
// 	int j;
// 	int fst_index;
// 	int snd_index;

// 	i = -1;
// 	while (data->line[i])
// 	{
// 		i++;
// 		if (data->line[i] == '\'')
// 		{
// 			fst_index = i;
// 			j = i;
// 			while (data->line[j] != '\'')
// 			{
// 				j++;
// 				if (data->line[j] == '\0')
// 					break;
// 				else if (data->line[j] == '\'' && data->line[j + 1] != '\'')
// 				{
// 					snd_index = j;
// 					data->fill_tab[index_j] = ft_substr(data->line, fst_index, snd_index);
// 					return (snd_index);
// 				}
// 			}
// 		}
// 	}
// 	return (index_i);
// }

// int verif_quote_argument(t_data *data)
// {
// 	data->check_tab.simple_quote(data);
// 	double_quote(data);
// }
