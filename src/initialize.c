#include "../includes/cub3d.h";

void		init_ray_params(t_raycaster *raycaster, t_data *data, t_player *player)
{
	data->mlx_ptr = NULL;
	data->win = NULL;
	raycaster->ceil = 0;
	raycaster->floor = 0;
	init_player(player);
	raycaster->sprite->save_bpm = raycaster->save;
	raycaster->sprite->sprites_count = raycaster->sprite->num_sprites;
	raycaster->sprite = ft_calloc(sizeof(t_sprite) * raycaster->sprite->num_sprites, 1);
	raycaster->sprite->sprites_buffer = (double *)malloc(sizeof(double) * raycaster->w);
}
