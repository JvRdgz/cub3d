/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:51:03 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/03 20:52:23 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*change_char(char *line, char a, char b)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == a)
			line[i] = b;
		i++;
	}
	return (line);
}

void	error_xpm(char *final)
{
	int			i;

	i = ft_strlen(final) - 1;
	while (final[i] == ' ' || final[i] == '\t')
		i--;
	if ((final[i] != 'm')
		&& (final[i - 1] != 'p')
		&& (final[i - 2] != 'x')
		&& (final[i - 3] != '.'))
		print_err("Formato de texturas incorrecto.");
}

void	check_errors(char *line, t_config config)
{
	if (((check_lines(line, " NSR\tECFW") == 0 && line[0] != '\0')
			&& (who_needs_a_map(line, "102 NSWE\t", 0, 0) == 0)))
		print_err("Elimine los caracteres sobrantes.");
	if (who_needs_a_map(line, "102 NSWE\t", 0, 0) == 1 && config.flag != 8)
		print_err("Declare correctamente los parametros delante del mapa");
	if (who_needs_a_map(line, " NSCFRWE", 0, 0) == 1)
		print_err("Elimine los caracteres sobrantes.");
}
