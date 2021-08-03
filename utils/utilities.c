/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:13:07 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/03 21:14:49 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ace(char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	kill(str);
	str = va_arg(ap, char *);
	while (str)
		kill(str);
	va_end(ap);
}

void	kill(char *str)
{
	free(str);
	str = NULL;
}

void	double_kill(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		kill(str[i]);
		i++;
	}
	free(str);
}

int	what_is_higher(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	white_spaces(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
