
#include "minishell.h"
#include <string.h> 

void	init_struct_value(int nb, t_data *data)
{
	data->var = NULL;
	data->cmpt_line = 0;
	data->clean_var = NULL;
	data->check_tab.j = 0;
	data->check_tab.i = 0;
	data->check_tab.len = 0;
    if (nb == 1)
        data->line = NULL;
    data->fill_tab = NULL;
}

void	malloc_envp(char **env, t_data *data)
{
	int i;

    i = 0;
	data->envp = malloc(sizeof(char *) * 4096);
	while (env[i])
	{
		data->envp[i] = ft_substr(env[i], 0, ft_strlen(env[i]));
		i++;
	}
    data->len_envp = i - 1;
	data->envp[i] = NULL;
}

// void    second_parsing(t_data *data)
// {
//     int i;
//     int len;
//     char *tmp;
//     char *tmp2;

//     i = 0;
//     free(data->line);
//     data->line = NULL;
//     while (data->fill_tab[i])
//     {
//         tmp = NULL;
//         tmp2 = NULL;
//         if (i > 0)
//         {
//             len = ft_strlen(data->line);
//             tmp = malloc(sizeof(char) * len + 3);
//             tmp[len + 1] = ' ';
//             tmp[len + 2] = '\0';
//             free(data->line);
//             data->line = tmp;
//             free(tmp);
//         }
//         tmp = ft_strdup(data->line);
//         tmp2 = ft_strdup(data->fill_tab[i]);
//         if (data->line)
//             free(data->line);
//         if (tmp && tmp2)
//             data->line = (unsigned char *)ft_strjoin(tmp, tmp2);
//         else if (tmp)
//             data->line = (unsigned char *)ft_strdup(tmp);
//         else if (tmp2)
//             data->line = (unsigned char *)ft_strdup(tmp2);
//         free(data->fill_tab[i]);
//         if (tmp)
//             free(tmp);
//         if (tmp2)
//             free(tmp2);
//         i++;
//     }
//     free(data->fill_tab);
//     init_struct_value(0, data);
//     first_parser(data);
//     fill_tab_arg(data);
// }

int	main(int ac, char **av, char **env)
{
    t_data data;

    (void)ac;
    (void)av;
    malloc_envp(env, &data);
	while (1)
	{
        init_struct_value(0, &data);
		data.line = readline("🔥👹\033[1;31m Minihell \033[0m👹🔥➜ ");
        
        if (data.line[0] != '\0')
        {
            printf("%s\n\n", data.line);
            first_parser(&data);
            fill_tab_arg(&data);
            // second_parsing(&data);
            int i;
            search_path(&data);
            if (ft_strcmp(data.fill_tab[0], "export") == 0)
                export(data.fill_tab, &data);
            if (ft_strcmp(data.fill_tab[0], "echo") == 0)
                echo(data.fill_tab);
            i = 0;
            while (data.fill_tab[i])
	        {
                printf("%s\n", data.fill_tab[i]);
                free(data.fill_tab[i]);
                i++;
            }
            i = 0;
            while (data.envp[i])
            {
                free(data.envp[i]);
                i++;
            }
            free(data.envp);
            // if (data.cmpt_line > 0)
            //     free(data.line);
            free(data.fill_tab);
            if (ft_strcmp(data.fill_tab[0], "exit") == 0)
                return (exit_lol(data.fill_tab));
        }
		free(data.line);
	}

	return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	t_data data;

// 	(void)ac;
// 	data.envp = env;
// 	data.line = (unsigned char *)av[1];
// 	printf("%s\n\n", data.line);
// 	init_struct_value(&data);
// 	first_parser(&data);
// 	fill_tab_arg(&data);
// 	int i;
// 	search_path(&data);
// 	export(&data);
// 	i = 0;
// 	while (data.fill_tab[i])
// 	{
// 		printf("%s\n", data.fill_tab[i]);
// 		free(data.fill_tab[i]);
// 		i++;
// 	}
// 	if (data.cmpt_line > 0)
// 		free(data.line);
// 	free(data.fill_tab);
// 	return (0);
// }