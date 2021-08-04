/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 22:05:26 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/04 22:32:17 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_countwords(char const *s, char c)
{
	int	wrds;
	int	wrd_fnd;

	wrds = 0;
	wrd_fnd = 0;
	while (*s != '\0')
	{
		if (*s != c && wrd_fnd == 0)
		{
			wrds++;
			wrd_fnd = 1;
		}
		else if (*s == c)
			wrd_fnd = 0;
		s++;
	}
	return (wrds);
}

int	ft_char(char const *s, char c)
{
	int	cs;

	cs = 0;
	while (*s != c && *s != '\0')
	{
		cs++;
		s++;
	}
	return (cs);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != (int)0)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_fillstr(int j, char **wrds, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		wrds[j][i++] = *s;
		s++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**wrds;
	int		wrd_l;
	int		j;

	wrds = ft_calloc(ft_countwords(s, c) + 1, sizeof(char *));
	if (!wrds)
		return (NULL);
	j = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		wrd_l = ft_char(s, c);
		wrds[j] = ft_calloc((wrd_l + 1), sizeof(char));
		if (wrd_l > 0 && !(wrds))
		{
			ft_free_matrix(wrds);
			return (NULL);
		}
		ft_fillstr(j, wrds, s, c);
		s += wrd_l;
		j++;
	}
	return (wrds);
}
