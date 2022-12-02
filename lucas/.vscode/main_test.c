#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
    int i;
    int l = ft_atoi(av[1]);
    // i = strlen(av[1]);

    char **str = malloc(sizeof(char *) * 2);
    str[0] = av[2];
    i = 3;
    str[1] = NULL;
    if (l > 2)
    {
        str = malloc(sizeof(char *) * l);
    }
    while (av[i])
    {
        str[i] = av[3];
        i++;
    }
    i = -1;
    while (++i && str[i])
        printf("%s\n", str);
    free(str);
    return (0);
}