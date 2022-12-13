/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:51:01 by luserbu           #+#    #+#             */
/*   Updated: 2022/12/13 14:51:06 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [line_parser.c]
// char	*special_check(char *str, t_parse *parse);
// int	first_parser(t_parse *parse);
// ------------------PROTOTYPE POUR LE ".h"------------------

char	*special_check(char *str, t_parse *parse)
{
	parse->index.i = 0;
	while (str[parse->index.i])
	{
		str = condition_special_check(str, parse->index.i, parse);
		if (!str[parse->index.i])
			break ;
		parse->index.i++;
	}
	parse->index.i = 0;
	return (str);
}

int	first_parser(t_parse *parse)
{
	int	i;
	int	temp;

	i = 0;
	if (!peer_quote(parse->line))
	{
		ft_error(NULL, 0x0111, TRUE, parse);
		return (FALSE);
	}
	if (!check_dollar_character(parse->line))
	{
		ft_error(parse->line, 0x0112, TRUE, parse);
		return (FALSE);
	}
	if (check_quoted_string(parse->line) || check_unquoted_string(parse->line))
		parse->line = special_check(parse->line, parse);
	parse->line = second_parser(parse->line, parse);
	return (TRUE);
}
