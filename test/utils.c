/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:35:07 by luserbu           #+#    #+#             */
/*   Updated: 2022/10/17 19:39:06 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**ft_tab(const char *s, char c, char **final_tab);
static size_t	ft_words(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**final_tab;

	if (!s)
		return (NULL);
	final_tab = malloc(sizeof(char *) * (ft_words(s, c)));
	if (!final_tab)
		return (NULL);
	final_tab = ft_tab(s, c, final_tab);
	return (final_tab);
}

static size_t	ft_words(const char *s, char c)
{
	size_t	i;
	size_t	cmpt;

	i = 0;
	if (s[i] == c || s[i] == 0)
		cmpt = 0;
	else
		cmpt = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			cmpt++;
		i++;
	}
	return (cmpt + 1);
}

char	**ft_tab(const char *s, char c, char **final_tab)
{
	unsigned int	i;
	size_t			len;
	size_t			y;

	y = 0;
	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i + len] != c && s[i + len])
			len++;
		if (len > 0)
		{
			final_tab[y] = ft_substr(s, i, len);
			y++;
		}
		i += len;
		while (s[i] == c && s[i])
			i++;
		len = 0;
	}
	final_tab[y] = NULL;
	return (final_tab);
}

char	*last_tab(const char *s, unsigned int start, size_t len, char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= (size_t)ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	if (len >= (size_t)ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof (*s) * (len + 1));
	if (!str)
		return (NULL);
	str = last_tab(s, start, len, str);
	return (str);
}

char	*last_tab(const char *s, unsigned int start, size_t len, char *str)
{
	size_t	i;
	size_t	si;

	si = 0;
	i = 0;
	while (s[i])
	{
		if (i >= (size_t)start && si < len)
		{
			str[si] = s[i];
			si++;
		}
		i++;
	}
	str[si] = '\0';
	return (str);
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
