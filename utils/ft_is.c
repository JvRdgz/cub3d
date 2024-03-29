/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:01:04 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/03 21:04:00 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	char_to_num(char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 1;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if ((str[i] > '9') || (str[i] < '0'))
			x = 0;
		i++;
	}
	return (x);
}

char	*give_me_digit_without_spaces(char *str)
{
	int		i;
	int		x;
	char	*finally;

	i = 0;
	x = 0;
	finally = ft_calloc(ft_strlen(str), 1);
	if (!finally)
		return (NULL);
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '\t') && (str[i] < '0' || str[i] > '9'))
			return ("FAIL");
		i++;
	}
	i = 0;
	while (str[i++])
		if (str[i] <= '9' && str[i] >= '0')
			finally[x++] = str[i];
	return (finally);
}
