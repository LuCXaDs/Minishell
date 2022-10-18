/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:13:06 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/10/11 15:54:33 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_check_tab
{
	int k_s_q;
	int	k_d_q;
	int simple_quote;
	int double_quote;
	int	dollar;
}			t_check_tab;
typedef struct s_data
{
	t_check_tab		check_tab;
	unsigned char	*line;
	char			**fill_tab;
}		t_data;

// {file} [fill_tab_arg.c]
int ft_strlen(const char *s);
void	fill_tab_arg(t_data *data);
// {file} [utils.c]
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
# endif
