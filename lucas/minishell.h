/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:13:06 by gtelnoff          #+#    #+#             */
/*   Updated: 2022/12/02 15:48:21 by luserbu          ###   ########.fr       */
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

typedef struct s_check_tab
{
	int				i;
	int				j;
	int				len;
}					t_check_tab;

typedef struct s_data
{
	t_check_tab		check_tab;
	char			**env;
	char			**envp;
	char			**export;
	char			*print_path;
	char			*var;
	char			*clean_var;
	char			*path;
	unsigned char	*line;
	int				cmpt_line;
	int				len_envp;
	char			**fill_tab;
}					t_data;

// <-------------> {file}->[echo.c]
char				*ft_strjoin_free(char *s1, char *s2, int index);
char				*double_tab_to_simple(char **array, int n);
int					verif_arg_echo(char *tab);
void				echo(char **tab);

// <-------------> {file}->[exit.c]
int					verif_letter(char *tab);
int					loop_strdiff(int i, int j, char *s1, char *s2);
int					ft_strdiff(char *s1, char *s2);
int				exit_lol(char **tab);

// <-------------> {file}->[export_utils.c]
int					verif_var_character(char *tab);
char				*var_without_no_more(char *tab);

// <-------------> {file}->[export.c]
int					check_same_var(char *tab, t_data *data);
char				*add_arg_to_var(int index, char *tab, t_data *data);
int					loop_export(char **tab, int i, int j, t_data *data);
void				export(char **tab, t_data *data);

// <-------------> {file}->[fill_tab_arg_utils.c]
int					cmpt_words(char *s);
int					check_character(int i, int len, unsigned char *str, int nb);
void				condition_fill_tab(t_data *data);

// <-------------> {file}->[fill_tab_arg.c]
void				fill_tab_arg(t_data *data);
void				find_and_split(t_data *data);
void				find_quote(char c, t_data *data);
void				split_special_character(int len, t_data *data);
int					find_quote_next_to_char(char c, t_data *data);

// <-------------> {file}->[line_parser.c]
void				first_parser(t_data *data);
void				check_error_special_char(int i, char *str);
char				*clean_read_line(int i, char c, char *str);
int					check_quote_and_char_next_to(int i, char c, char *str);

// <-------------> {file}->[print_env_utils.c]
int					ft_strlentab(char **tab);
int					check_quote(int i, char c, t_data *data);
char				*clean_path(char *path, t_data *data);
int					ft_str_path(char *big, char *little);
int					chech_correct_path_arg(int i, char *str);

// <-------------> {file}->[print_env.c]
void				change_tab_path(int i, int temp, t_data *data);
int					loop_find_path(char *no_dollar, t_data *data);
int					find_path(int index_i, int index_j, t_data *data);
int					loop_search_path(int i, int j, int temp, t_data *data);
void				search_path(t_data *data);

// <-------------> {file}->[print_export.c]
char				*add_quote2(char *tmp, int count, int i, int j);
char				*add_quote(char *str);
void				add_argument_into_export(t_data *data);
void				sort_loop(t_data *data);
void				print_export(t_data *data);

// <-------------> {file}->[utils01.c]
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);

// <-------------> {file}->[utils02.c]
int					ft_strlen(const char *s);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(const char *s);

// <-------------> {file}->[utils03.c]
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					strlen_stop(char *str, char c);
int					ft_atoi(const char *nptr);
#endif
