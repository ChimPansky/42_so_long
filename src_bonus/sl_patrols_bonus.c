/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_patrols_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:13:17 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/27 15:37:42 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	sl_try_move_patrol(t_sl_game *game, t_sl_unit *dragon,
	int d_x, int d_y)
{
	t_sl_point	new_field;

	sl_point_copy(&new_field, dragon->pos, d_x, d_y);
	new_field.symbol = game->map->fields[new_field.y][new_field.x];
	if (!ft_strchr(SL_MAP_PATROL_WALKABLE, new_field.symbol))
		return ;
	game->map->fields[dragon->pos->y][dragon->pos->x] = SL_MAP_PATH;
	game->map->fields[new_field.y][new_field.x] = SL_MAP_PATROL;
	mlx_put_image_to_window(game->mlx->mlx_connection, game->mlx->mlx_window,
		game->mlx->mlx_img_path, dragon->pos->x * game->graphics_size,
		dragon->pos->y * game->graphics_size);
	if (new_field.symbol == SL_MAP_PLAYER)
	{
		sl_player_dies(game);
		return ;
	}
	mlx_put_image_to_window(game->mlx->mlx_connection, game->mlx->mlx_window,
		game->mlx->mlx_img_patrol, new_field.x * game->graphics_size,
		new_field.y * game->graphics_size);
	sl_point_copy(dragon->pos, dragon->pos, d_x, d_y);
}

int	sl_move_patrols(t_sl_game *game)
{
	t_sl_unit	*dragon;
	int			random_nr;

	dragon = game->patrols;
	while (dragon)
	{
		random_nr = rand() % 4;
		if (random_nr == 0)
			sl_try_move_patrol(game, dragon, 1, 0);
		if (random_nr == 1)
			sl_try_move_patrol(game, dragon, 0, 1);
		if (random_nr == 2)
			sl_try_move_patrol(game, dragon, -1, 0);
		if (random_nr == 3)
			sl_try_move_patrol(game, dragon, 0, -1);
		dragon = dragon->next;
	}
	return (SUCCESS);
}
