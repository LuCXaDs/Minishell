/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:59:21 by luserbu           #+#    #+#             */
/*   Updated: 2022/12/02 15:48:03 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ------------------PROTOTYPE POUR LE ".h"------------------
// {file} [utils02.c]
// size_t	ft_strlcat(char *dst, const char *src, size_t size);
// char	*ft_strcat(char *dst, const char *src);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strncpy(char *dest, char *src, unsigned int n);
// char	*ft_strdup(const char *s);
// ------------------PROTOTYPE POUR LE ".h"------------------

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	y;

	i = ft_strlen(dst);
	y = ft_strlen(src);
	if (size == 0 || i > size)
		return (size + y);
	if (!*src)
		return (i);
	j = 0;
	while (src[j] && (i + j < size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + y);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * (i + j));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (i + j));
	ft_strlcat(str, s2, (i + j));
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	char	*st;

	if (!s)
		return (NULL);
	st = (char *)s;
	i = 0;
	while (st[i])
		i++;
	str = malloc(sizeof (char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (st[++i])
		str[i] = st[i];
	str[i] = '\0';
	return (str);
}

int	strlen_stop(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	final;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if ((nptr[i] == '-' || nptr[i] == '+')
			&& (!(nptr[i + 1] >= '0' && nptr[i + 1] <= '9')))
			return (0);
		else if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	final = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		final = (final * 10) + (nptr[i] - 48);
		i++;
	}
	return (final * neg);
}
