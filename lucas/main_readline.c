
#include "minishell.h"
#include <string.h> 

// void	init_struct_value(int nb, t_parse *parse)
// {
// 	parse->var = NULL;
// 	parse->cmpt_line = 0;
// 	parse->clean_var = NULL;
// 	parse->index.j = 0;
// 	parse->index.i = 0;
// 	parse->index.len = 0;
//     if (nb == 1)
//         parse->line = NULL;
//     parse->fill_tab = NULL;
// }

// void	malloc_envp(char **env, t_parse *parse)
// {
// 	int i;

//     i = 0;
// 	parse->envp = ft_calloc(sizeof(char *), 4096);
// 	while (env[i])
// 	{
// 		parse->envp[i] = ft_substr(env[i], 0, ft_strlen(env[i]));
// 		i++;
// 	}
//     parse->len_envp = i - 1;
// 	parse->envp[i] = NULL;
// }

int	main(int ac, char **av, char **env)
{
    t_parse parse;

    (void)ac, (void)av;
    malloc_envp(env, &parse);
	while (1)
	{
        init_struct_value(&parse);
		parse.line = readline("🔥👹\033[1;31m Minihell \033[0m👹🔥➜ ");
        if (parse.line[0] != '\0')
        {
            parsing(&parse);
            // if (first_parser(&parse))
            // {
            //     fill_tab_arg(&parse);
            //     search_path(&parse);
            //     if (strcmp(parse.fill_tab[0], "export") == 0)
            //         export(parse.fill_tab, &parse);
            //     if (strcmp(parse.fill_tab[0], "echo") == 0)
            //         echo(parse.fill_tab);
            //     if (strcmp(parse.fill_tab[0], "exit") == 0)
            //         exit_function(parse.fill_tab, &parse);
            //     ft_free(&parse, TRUE);
            // }
            // else
            //     ft_free(&parse, FALSE);
        }
	}
}
