/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:13:06 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/10/18 17:31:29 by luserbu          ###   ########.fr       */
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
	int i;
	int	j;
	int	len;
}			t_check_tab;
typedef struct s_data
{
	t_check_tab		check_tab;
	char			**env;
	char			**export;
	char			*print_path;
	char			*var;
	char 			*clean_var;
	unsigned char	*line;
	char			**fill_tab;
}		t_data;

// {file} [fill_tab_arg.c]
int ft_strlen(const char *s);
void	fill_tab_arg(t_data *data);
void	first_parser(t_data *data);
// {file} [utils.c]
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
// {file} print_env.c
void	search_path(t_data *data);
//	{file} [export.c]
void	sort_list(t_data *data);
void	export(t_data *data);
# endif
