/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:51:01 by luserbu           #+#    #+#             */
/*   Updated: 2022/10/19 18:31:38 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [line_parser.c]
// char	*first_parser(char *line);
// void	check_error_special_char(int i, char *str);
// char	*clean_read_line(int i, char c, char *str);
// int check_quote_and_char_next_to(int i, char c, char *str);
// ------------------PROTOTYPE POUR LE ".h"------------------

unsigned char	*first_parser(unsigned char *line)
{
	char	*str;
	int		i;

	str = (char *)line;
	i = 0;
	while (str[i])
	{
		check_error_special_char(i, str);
		if ((str[i] == '\'' || str[i] == '\"') && str[i + 1])
			str = clean_read_line(i, str[i], str);
		i++;
	}
	line = (unsigned char *)str;
	printf("%s\n\n", line);
	return (line);
}

void	check_error_special_char(int i, char *str)
{
	if (str[i] == '<' && str[i])
		if (str[i + 1] == '<' && str[i + 1])
			if (str[i + 2] == '<' && str[i + 2])
				printf("Error\n");
	if (str[i] == '>' && str[i])
		if (str[i + 1] == '>' && str[i + 1])
			if (str[i + 2] == '>' && str[i + 2])
				printf("Error\n");
	if (str[i] == '|' && str[i])
		if (str[i + 1] == '|' && str[i + 1])
			printf("Error\n");
	if (str[i] == '&' && str[i])
		if (str[i + 1] == '&' && str[i + 1])
			printf("Error\n");
}

char	*clean_read_line(int i, char c, char *str)
{
	static int	no_malloc = 0;
	int			j;
	char		*clean;

	if (check_quote_and_char_next_to(i, c, str) == -1)
		return (str);
	j = 0;
	clean = malloc(sizeof(char) * (ft_strlen(str) - 1));
	while (j < i)
	{
		clean[j] = str[j];
		j++;
	}
	i += 1;
	while (str[i] != c)
		clean[j++] = str[i++];
	i += 1;
	while (str[i])
		clean[j++] = str[i++];
	clean[j] = '\0';
	if (no_malloc != 0)
		free(str);
	no_malloc++;
	return (clean);
}

int	check_quote_and_char_next_to(int i, char c, char *str)
{
	i += 1;
	while (str[i] != c && str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || str[i] == c)
			i++;
		else
			return (-1);
	}
	return (1);
}
