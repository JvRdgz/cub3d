/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:16:32 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/05 20:32:55 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	drifting_r_path(char *line, t_config *config)
{
	if ((line[config->i] == 'R') && (white_spaces(line[config->i + 1])))
		*config = check_r(line, *config);
	if (((line[config->i] == 'N') && (line[config->i + 1] == 'O')
			&& (white_spaces(line[config->i + 2])))
		|| ((line[config->i] == 'S') && (line[config->i + 1] == 'O')
			&& (white_spaces(line[config->i + 2])))
		|| ((line[config->i] == 'W') && (line[config->i + 1] == 'E')
			&& (white_spaces(line[config->i + 2])))
		|| ((line[config->i] == 'E') && (line[config->i + 1] == 'A')
			&& (white_spaces(line[config->i + 2])))
		|| ((line[config->i] == 'S') && (white_spaces(line[config->i + 1]))))
		*config = check_cardinals(&line[config->i], *config);
}

t_config	check_file(char *line, t_config config)
{
	config.i = 0;
	while (line[config.i] != '\0')
	{
		drifting_r_path(line, &config);
		if (((line[config.i] == 'F') && (line[config.i + 1] == ' '))
			|| ((line[config.i] == 'C') && (line[config.i + 1] == ' ')))
			config = check_ceil_floor(line, config);
		if ((line[config.i] == '1') && ((line[config.i + 1] == '1')
				|| (line[config.i + 1] == '2') || (line[config.i + 1] == '3')
				|| (line[config.i + 1] == '0') || (line[config.i + 1] == 'N')
				|| (line[config.i + 1] == 'S') || (line[config.i + 1] == 'W')
				|| (line[config.i + 1] == 'E')) && (config.flag == 8))
		{
			if (ft_strlen(line) > config.map_max_rows)
				config.map_max_rows = ft_strlen(line);
			config.map_max_lines += 1;
			while (line[config.i] != '\0')
				config.i++;
		}
		if (line[config.i] != '\0')
			config.i++;
	}
	return (config);
}

int	check_lines(char *line, char *chars)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		while (chars[j] != '\0')
		{
			if (line[i] == chars[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_config	load_file(char *file, t_config config)
{
	int			fd;
	char		*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_err("Error al abrir el archivo.");
	while (get_next_line(fd, &line))
	{
		check_errors(line, config);
		config.i = 0;
		config = check_file(line, config);
		kill(line);
	}
	config = check_file(line, config);
	kill(line);
	close(fd);
	check_params(config);
	return (config);
}

t_config	file_procesator(char *file, int argc)
{
	t_config	config;

	if (file[ft_strlen(file) - 1] != 'b' && file[ft_strlen(file) - 2] != 'u'
		&& file[ft_strlen(file) - 3] != 'c' && file[ft_strlen(file) - 4] != '.')
		printf("El mapa no tiene la extension .cub");
	reset_t_config(&config);
	config = load_file(file, config);
	config.mapa = read_map(file, &config);
	if (config.player_begin[0] == 0 && config.player_begin[1] == 0)
		print_err("Falta especificar el jugador en el mapa.");
	return (config);
}
