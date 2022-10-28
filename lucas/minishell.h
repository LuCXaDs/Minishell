/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:13:06 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/10/24 22:29:36 by luserbu          ###   ########.fr       */
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
	char			**envp;
	char			**export;
	char			*print_path;
	char			*var;
	char 			*clean_var;
	unsigned char	*line;
	char			**fill_tab;
}		t_data;

// {file} [fill_tab_arg_utils.c]
int	cmpt_words(char *s);
int	check_character(int i, int len, unsigned char * str, int nb);

// {file} [fill_tab_arg.c]
void	fill_tab_arg(t_data *data);
void	find_and_split(t_data *data);
void	find_quote(char c, t_data *data);
void 	split_special_character(int len, t_data *data);
int		find_quote_next_to_char(char c, t_data *data);

// {file} [line_parser.c]
unsigned char	*first_parser(unsigned char *line);
void	check_error_special_char(int i, char *str);
char	*clean_read_line(int i, char c, char *str);
int check_quote_and_char_next_to(int i, char c, char *str);

// {file} [utils01.c]
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// {file} [utils02.c]
int	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int	ft_strcmp(char *s1, char *s2);

// {file} [utils03.c]
size_t	ft_strlcat(char *dst, const char *src, size_t size);
// char	*ft_strcat(char *dst, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);

// {file} [export.c]
void	export(t_data *data);

void	search_path(t_data *data);

# endif
