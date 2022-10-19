/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:59:21 by luserbu           #+#    #+#             */
/*   Updated: 2022/10/19 18:25:53 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [utils02.c]
// int	ft_strlen(const char *s);
// char	*ft_strnstr(const char *big, const char *little, size_t len);
// ------------------PROTOTYPE POUR LE ".h"------------------

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	m;

	i = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (little[0] == big[i])
		{
			m = 0;
			while (little[m] == big[i + m] && i + m < len)
			{
				m++;
				if (little[m] == '\0')
					return ((char *)big + i);
			}
		}
		i++;
	}
	return (NULL);
}
