/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:17:21 by jarodrig          #+#    #+#             */
/*   Updated: 2021/07/14 22:25:14 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			drifting_r_path(char *line, t_raycaster *raycaster)
{
	if ((line[raycaster->i] == 'R') && (white_spaces(line[raycaster->i + 1])))
		*raycaster = check_r(line, *raycaster);
	if (((line[raycaster->i] == 'N') && (line[raycaster->i + 1] == 'O')
	&& (white_spaces(line[raycaster->i + 2]))) ||
	((line[raycaster->i] == 'S') && (line[raycaster->i + 1] == 'O') &&
	(white_spaces(line[raycaster->i + 2]))) ||
	((line[raycaster->i] == 'W') && (line[raycaster->i + 1] == 'E') &&
	(white_spaces(line[raycaster->i + 2]))) ||
	((line[raycaster->i] == 'E') && (line[raycaster->i + 1] == 'A') &&
	(white_spaces(line[raycaster->i + 2]))) ||
	((line[raycaster->i] == 'S') && (white_spaces(line[raycaster->i + 1]))))
		*raycaster = check_path(&line[raycaster->i], *raycaster);
}

t_raycaster		check_file(char *line, t_raycaster raycaster)
{
	raycaster.i = 0;
	while (line[raycaster.i] != '\0')
	{
		drifting_r_path(line, &raycaster);
		if (((line[raycaster.i] == 'F') && (line[raycaster.i + 1] == ' ')) ||
		((line[raycaster.i] == 'C') && (line[raycaster.i + 1] == ' ')))
			raycaster = check_ceil_floor(line, raycaster);
		if ((line[raycaster.i] == '1') && ((line[raycaster.i + 1] == '1') ||
		(line[raycaster.i + 1] == '2') || (line[raycaster.i + 1] == '3') ||
		(line[raycaster.i + 1] == '0') || (line[raycaster.i + 1] == 'N') ||
		(line[raycaster.i + 1] == 'S') || (line[raycaster.i + 1] == 'W') ||
		(line[raycaster.i + 1] == 'E')) && (raycaster.flag == 8))
		{
			if (ft_strlen(line) > raycaster.max_map_rows)
				raycaster.max_map_rows = ft_strlen(line);
			raycaster.max_map_lines += 1;
			while (line[raycaster.i] != '\0')
				raycaster.i++;
		}
		if (line[raycaster.i] != '\0')
			raycaster.i++;
	}
	return (raycaster);
}

int				check_lines(char *line, char *chars)
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

t_raycaster		load_file(char *file, t_raycaster raycaster)
{
	int			fd;
	int			ret;
	char		*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_err("Fallo al intentar abrir el archivo.");
	while (((ret = get_next_line(fd, &line)) > 0))
	{
		check_errors(line, raycaster);
		raycaster.i = 0;
		raycaster = check_file(line, raycaster);
		kill(line);
	}
	raycaster = check_file(line, raycaster);
	kill(line);
	close(fd);
	check_params(raycaster);
	return (raycaster);
}

t_raycaster		file_procesator(char *file, int argc)
{
	t_raycaster	raycaster;
	t_player 	player;

	if (file[ft_strlen(file) - 1] != 'b' && file[ft_strlen(file) - 2] != 'u' &&
	file[ft_strlen(file) - 3] != 'c' && file[ft_strlen(file) - 4] != '.')
		printf("El archivo que ingresa debe ser tener la extension .cub");
	reset_t_raycaster(&raycaster);
	raycaster = load_file(file, raycaster);
	raycaster.r_map = read_map(file, &raycaster);
	if (player.first_pos[0] == 0 && player.first_pos[1] == 0)
		print_err("Este mapa no puede ser usado sin un jugador");
	return (raycaster);
}
