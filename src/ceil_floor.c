/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:09:50 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/05 19:01:14 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_config	check_ceil_floor(char *line, t_config config)
{
	char		**splitter;
	char		conmut;

	if ((line[config.i] == 'C' && config.ceil[0] != -1)
		|| (line[config.i] == 'F' && config.floor[0] != -1))
		print_err("Valores de C o F duplicados.");
	conmut = line[config.i];
	check_ceil_floor2(line);
	while ((line[config.i] != '\0') && ((line[config.i] < '0')
			|| (line[config.i] > '9')))
		config.i++;
	splitter = ft_split(&line[config.i], ',');
	if (char_to_num(splitter[2]) != 1)
		splitter[2] = give_me_digit_without_spaces(splitter[2]);
	if ((splitter[3]) || (char_to_num(splitter[0]) != 1)
		|| (char_to_num(splitter[1]) != 1) || (char_to_num(splitter[2]) != 1))
		print_err("Formatos de C o F incorrectos.");
	check_cf(conmut, splitter, &config);
	while (line[config.i])
		config.i++;
	double_kill(splitter);
	return (config);
}

void	check_ceil_floor2(char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if ((line[i] == ',' && (line[i - 1] < '0' || line[i - 1] > '9'))
			|| (line[i] == ',' && (line[i + 1] < '0' || line[i + 1] > '9')))
			print_err("Formato de F C valido => 'x,x,x' en positivo");
		i++;
	}
}

void	check_cf(char conmut, char **splitter, t_config *config)
{
	if (conmut == 'C')
	{
		config->ceil[0] = ft_atoi(splitter[0]);
		config->ceil[1] = ft_atoi(splitter[1]);
		config->ceil[2] = ft_atoi(splitter[2]);
		config->flag += 1;
	}
	if (conmut == 'F')
	{
		config->floor[0] = ft_atoi(splitter[0]);
		config->floor[1] = ft_atoi(splitter[1]);
		config->floor[2] = ft_atoi(splitter[2]);
		config->flag += 1;
	}
}
