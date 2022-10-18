/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:33:18 by luserbu           #+#    #+#             */
/*   Updated: 2022/10/18 17:41:32 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_words(char *s)
/*	Found the number of words	*/
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
		if ((s[i] == c || s[i] == '\"' || s[i] == '\'' \
		|| s[i] == '|'  || s[i] == '<' || s[i] == '>') \
		&& s[i + 1] != c && s[i + 1] != 0)
			cmpt++;
		i++;
	}
	return (cmpt + 1);
}

void 	split_special_character(int len, t_data *data)
/*	Slit character	*/
{
	if (data->check_tab.len > 0)
	{
		data->fill_tab[data->check_tab.j] = ft_substr((const char *)data->line, \
		data->check_tab.i, data->check_tab.len);
		data->check_tab.j++;
	}
	data->fill_tab[data->check_tab.j] = ft_substr((const char *)data->line, \
	(data->check_tab.i + data->check_tab.len), len);
	data->check_tab.j++;
	data->check_tab.i += data->check_tab.len + len;
	data->check_tab.len = 0;
}

int		find_quote_next_to_char(char c, t_data *data)
/*	Search character if they are peer	*/
{
	int quote;

	quote = 0;
	quote = data->check_tab.i + data->check_tab.len + 1;
	while (data->line[quote] != c && data->line[quote])
		quote++;
	if (data->line[quote] == c)
		return (-1);
	return (1);
}

void	find_quote(char c, t_data *data)
/* Split character	*/
{
	int		quote;
	int		len_quote;

	len_quote = 0;
	quote = data->check_tab.i + 1;
	while (data->line[quote] != c && data->line[quote])
	{
		quote++;
		len_quote++;
	}
	if (data->line[quote] == c)
	{
		data->fill_tab[data->check_tab.j] = ft_substr((const char *)data->line, \
		data->check_tab.i, len_quote + 2);
		data->check_tab.j++;
		data->check_tab.i = quote + 1;
	}
}

void	find_and_split(t_data *data)
/*	Search special character next to character and split them and
	found if they are 2 simple quote or 2 double quote	*/
{
	while (data->line[data->check_tab.i + data->check_tab.len] != ' ' \
	&& data->line[data->check_tab.i + data->check_tab.len])
	{
		if (data->line[data->check_tab.i + data->check_tab.len] ==  '|' \
		|| data->line[data->check_tab.i + data->check_tab.len] ==  '>' \
		|| data->line[data->check_tab.i + data->check_tab.len] ==  '<')
		{
			if ((data->line[data->check_tab.i + data->check_tab.len] ==  '<' \
			&& data->line[data->check_tab.i + data->check_tab.len + 1] ==  '<') \
			|| (data->line[data->check_tab.i + data->check_tab.len] ==  '>' \
			&& data->line[data->check_tab.i + data->check_tab.len + 1] ==  '>'))
				split_special_character(2, data);
			split_special_character(1, data);
			break;
		}
		if (data->line[data->check_tab.i + data->check_tab.len] == '\'')
		{
			if (find_quote_next_to_char('\'', data) == -1)
				break;
		}
		else if (data->line[data->check_tab.i + data->check_tab.len] == '\"')
		{
			if (find_quote_next_to_char('\"', data) == -1)
				break;
		}
		data->check_tab.len++;
	}
}

void	fill_tab_arg(t_data *data)
/*	Fill table with arguments (readline)	*/
{
	data->fill_tab = malloc(sizeof(char *) * ft_words((char *)data->line) + 1);
	while (data->line[data->check_tab.i])
	{
		while (data->line[data->check_tab.i] == ' ' && data->line[data->check_tab.i])
			data->check_tab.i++;
		if (data->line[data->check_tab.i] == '\"')
			find_quote('\"', data);
		if (data->line[data->check_tab.i] == '\'')
			find_quote('\'', data);
		find_and_split(data);
		if (data->check_tab.len > 0)
		{
			data->fill_tab[data->check_tab.j] = ft_substr((const char *)data->line, \
			data->check_tab.i, data->check_tab.len);
			data->check_tab.j++;
		}
		data->check_tab.i += data->check_tab.len;
		while (data->line[data->check_tab.i] == ' ' && data->line[data->check_tab.i])
			data->check_tab.i++;
		data->check_tab.len = 0;
	}
	data->fill_tab[data->check_tab.j] = NULL;
}

void	first_parser(t_data *data)
{
	unsigned char *str;
	int i;

	str = data->line;
	i = 0;
	while (str[i])
	{
		if (str[i] == '<' && str[i])
			if (str[i + 1] == '<' && str[i + 1])
				if (str[i + 2] == '<' && str[i + 2])
					printf("Error\n");
		if (str[i] == '|' && str[i])
			if (str[i + 1] == '|' && str[i + 1])
				printf("Error\n");
		if (str[i] == '&' && str[i])
			if (str[i + 1] == '&' && str[i + 1])
				printf("Error\n");
		i++;
	}
}
