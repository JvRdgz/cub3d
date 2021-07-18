/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:37:29 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/18 12:49:56 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void			ace(char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	kill(str);
	while ((str = va_arg(ap, char *)))
		kill(str);
	va_end(ap);
}

void			kill(char *str)
{
	free(str);
	str = NULL;
}

void			double_kill(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		kill(str[i]);
		i++;
	}
	free(str);
}

int				what_is_higher(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int				white_spaces(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
