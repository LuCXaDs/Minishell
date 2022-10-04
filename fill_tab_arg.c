/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:33:18 by luserbu           #+#    #+#             */
/*   Updated: 2022/10/04 23:33:39 by luserbu          ###   ########.fr       */
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
char	*last_tab(const char *s, unsigned int start, size_t len, char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof (*s) * (len + 1));
	if (!str)
		return (NULL);
	str = last_tab(s, start, len, str);
	return (str);
}

char	*last_tab(const char *s, unsigned int start, size_t len, char *str)
{
	size_t	i;
	size_t	si;

	si = 0;
	i = 0;
	while (s[i])
	{
		if (i >= (size_t)start && si < len)
		{
			str[si] = s[i];
			si++;
		}
		i++;
	}
	str[si] = '\0';
	return (str);
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

int	simple_quote(t_data *data, int index_i, int index_j);

void	fill_tab_arg(t_data *data)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	data->fill_tab = malloc(sizeof(char *) * ft_words(data->line) + 1);
	while (data->line[i] == ' ')
		i++;
	k = i;
	while(data->line[i])
	{
		if (data->line[i] == ' ' || data->line[i + 1] == '\0');
		{
			data->fill_tab[j++] = ft_substr(data->line, k, (i - 1));
			while (data->line[i] == ' ' && data->line[i + 1] == ' ')
				i++;
			k = i + 1;
		}
		if (data->line[i] == '\'')
		{
			i = simple_quote(data, i, j);
			while (data->line[i] == ' ' && data->line[i + 1] == ' ')
				i++;
			j++;
			k = i + 1;
		}
		i++;
	}
}

int	simple_quote(t_data *data, int index_i, int index_j)
{
	int i;
	int j;
	int fst_index;
	int snd_index;

	i = -1;
	while (data->line[i])
	{
		i++;
		if (data->line[i] == '\'')
		{
			fst_index = i;
			j = i;
			while (data->line[j] != '\'')
			{
				j++;
				if (data->line[j] == '\0')
					break;
				else if (data->line[j] == '\'' && data->line[j + 1] != '\'')
				{
					snd_index = j;
					data->fill_tab[index_j] = ft_substr(data->line, fst_index, snd_index);
					return (snd_index);
				}
			}
		}
	}
	return (index_i);
}

// int verif_quote_argument(t_data *data)
// {
// 	simple_quote(data);
// 	double_quote(data);
// }
