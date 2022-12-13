/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:13:06 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/12/13 15:05:58 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define TRUE 1
# define FALSE 0

typedef struct s_index
{
	int		i;
	int		j;
	int		len;
}			t_index;

typedef struct s_parse
{
	t_index	index;
	char	**env;
	char	**envp;
	char	*print_path;
	char	*var;
	char	*clean_var;
	char	*path;
	char	*line;
	int		cmpt_line;
	int		len_envp;
	char	**fill_tab;
}			t_parse;

// -----------PROTOTYPE POUR LE MAKEFILE -----------
/*
print_export.c \
fill_tab_arg_utils.c \
fill_tab_arg.c \
line_parser.c \
print_env.c \
utils01.c \
utils02.c \
utils03.c \
export.c \
echo.c \
exit.c \
print_env_utils.c \
export_utils.c \
error.c \
line_parser_utils01.c \
line_parser_utils02.c \
line_parser_utils03.c \
free_exit.c \
utils04.
*/
// -----------PROTOTYPE POUR LE MAKEFILE -----------

//<------->{file}->[echo.c]
char		*ft_strjoin_free(char *s1, char *s2, int index);
char		*double_tab_to_simple(char **array, int n);
int			verif_arg_echo(char *str);
void		echo(char **tab);

//<------->{file}->[error.c]
void		ft_error_exit(char *str, int code);
void		ft_error_export(int code);
void		ft_error_parse(char *str, int code);
void		ft_error(char *str, int code, int free, t_parse *parse);

//<------->{file}->[exit.c]
int			verif_letter(char *tab);
int			loop_strdiff(int i, int j, char *s1, char *s2);
int			ft_strdiff(char *s1, char *s2);
int			exit_function(char **tab, t_parse *parse);

//<------->{file}->[export_utils.c]
int			verif_var_character(char *tab);
char		*var_without_no_more(char *tab);
int			is_this_character(char *str, char c);
int			check_other_identifier(char *str, int i);
int			check_valid_identifier(char *str);

//<------->{file}->[export.c]
int			check_same_var(char *tab, t_parse *parse);
char		*add_arg_to_var(int index, char *tab, t_parse *parse);
int			loop_export(char **tab, int i, int j, t_parse *parse);
void		export(char **tab, t_parse *parse);

//<------->{file}->[fill_tab_arg_utils.c]
int			cmpt_words(char *s);
int			check_character(int i, int len, char *str, int nb);
void		condition_fill_tab(t_parse *parse);

//<------->{file}->[fill_tab_arg.c]
void		fill_tab_arg(t_parse *parse);
void		find_and_split(t_parse *parse);
void		find_quote(char c, t_parse *parse);
void		split_special_character(int len, t_parse *parse);
int			find_quote_next_to_char(char c, t_parse *parse);

//<------->{file} [free_exit.c]
void		ft_free(t_parse *parse, int check);
void		ft_exit(unsigned char c, t_parse *parse);

//<------->{file} [line_parser_utils01.c]
int			check_quote_in_quote(char *str, char c, int i);
int			peer_quote(char *str);
int			check_quote_charactere(char *str, char c, int i);
int			check_quoted_string(char *str);
int			check_unquoted_string(char *str);

//<------->{file} [line_parser_utils02.c]
int			condition_clean_rl(char *str, char *clean, char c, int i);
char		*clean_read_line(int i, char c, char *str);
int			strnlen_stop(char *str, char c, int size);
char		*clean_line(int i, char c, char *str);

//<------->{file} [line_parser_utils03.c]
char		*condition_special_check(char *str, int i, t_parse *parse);
char		*check_quotes(char *str, int i, t_parse *parse);
char		*second_parser(char *str, t_parse *parse);
int			check_dollar_character(char *str);
int			check_quote_and_char_next_to(int i, char c, char *str);

//<------->{file}->[line_parser.c]
int			first_parser(t_parse *parse);
void		check_error_special_char(int i, char *str);
char		*clean_read_line(int i, char c, char *str);
int			check_quote_and_char_next_to(int i, char c, char *str);

//<------->{file}->[parsing.c]
void		init_struct_value(t_parse *parse);
void		malloc_envp(char **env, t_parse *parse);
char		**parsing(t_parse *parse);

//<------->{file}->[print_env_utils.c]
int			ft_tablen(char **tab);
int			check_quote(int i, char c, t_parse *parse);
char		*clean_path(char *path, t_parse *parse);
int			ft_str_path(char *big, char *little);
int			chech_correct_path_arg(int i, char *str);

//<------->{file}->[print_env.c]
void		change_tab_path(int i, int temp, t_parse *parse);
int			loop_find_path(char *no_dollar, t_parse *parse);
int			find_path(int index_i, int index_j, t_parse *parse);
int			loop_search_path(int i, int j, int temp, t_parse *parse);
void		search_path(t_parse *parse);

//<------->{file}->[print_export.c]
char		*add_quote2(char *tmp, int count, int i, int j);
char		*add_quote(char *str);
void		add_argument_into_export(t_parse *parse);
void		sort_loop(t_parse *parse);
void		print_export(t_parse *parse);

//<------->{file}->[utils01.c]
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

//<------->{file}->[utils02.c]
int			ft_strlen(const char *s);
char		*ft_strnstr(const char *big, const char *little, size_t len);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(const char *s);

//<------->{file}->[utils03.c]
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strjoin(char const *s1, char const *s2);

//<------->{file}->[utils04.c]
char		*ft_strdup(const char *s);
int			strlen_stop(char *str, char c);
int			ft_atoi(const char *nptr);

#endif
