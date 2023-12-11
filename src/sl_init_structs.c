/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:16:36 by tkasbari          #+#    #+#             */
/*   Updated: 2023/12/04 11:24:11 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_init_point(t_sl_point *point)
{
	if (!point)
		return ;
	point->x = 0;
	point->y = 0;
	point->symbol = 0;
}

void	sl_init_unit(t_sl_unit *unit)
{
	if (!unit)
		return ;
	unit->pos = NULL;
	unit->moveable = false;
	unit->next = NULL;
}

void	sl_init_map(t_sl_map *map)
{
	if (!map)
		return ;
	map->size = NULL;
	map->fields = NULL;
}

void	sl_init_graphics(t_sl_game *game, t_mlx_graphics *mlx)
{
	int	i;

	i = 0;
	if (!mlx)
		return ;
	mlx->mlx_connection = mlx_init();
	if (!mlx->mlx_connection)
		sl_error_exit(game, ERR_MLX_INIT);
	mlx->mlx_img_player = NULL;
	mlx->mlx_img_token = NULL;
	mlx->mlx_img_wall = NULL;
	mlx->mlx_img_path = NULL;
	mlx->mlx_img_exit_closed = NULL;
	mlx->mlx_img_exit_open = NULL;
	mlx->mlx_img_game_won = NULL;
	mlx->mlx_img_game_lost = NULL;
}

void	sl_init_game(t_sl_game *game)
{
	if (!game)
		return ;
	game->map = NULL;
	game->player = NULL;
	game->tokens = NULL;
	game->exit = NULL;
	game->mlx = NULL;
	game->graphics_size = 0;
	game->moves = 0;
	game->exit_open = false;
	game->player_alive = true;
	game->game_won = false;
	game->game_aborted = false;
	game->timer = 0;
}
