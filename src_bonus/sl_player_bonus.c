/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:08:54 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/27 20:24:17 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_print_moves(t_sl_game *game)
{
	int	i;
	int	nb;

	nb = game->moves;
	i = 0;
	if (game->moves > 999999)
		return ;
	if (!game->moves)
	{
		mlx_put_image_to_window(game->mlx->mlx_connection,
			game->mlx->mlx_window, game->mlx->mlx_img_moves, 0, 0);
		while (i < 6)
			mlx_put_image_to_window(game->mlx->mlx_connection,
				game->mlx->mlx_window, game->mlx->mlx_img_digits[0],
				(float)(6 - i++ - 1) / 2 * game->graphics_size,
				0.48 * game->graphics_size);
	}
	while (nb)
	{
		mlx_put_image_to_window(game->mlx->mlx_connection,
			game->mlx->mlx_window, game->mlx->mlx_img_digits[nb % 10],
			(float)(6 - i++ - 1) / 2 * game->graphics_size,
			0.48 * game->graphics_size);
		nb /= 10;
	}
}

void	sl_player_dies(t_sl_game *game)
{
	game->player_alive = false;
	mlx_put_image_to_window(game->mlx->mlx_connection, game->mlx->mlx_window,
		game->mlx->mlx_img_player_dead,
		game->player->pos->x * game->graphics_size,
		game->player->pos->y * game->graphics_size);
	mlx_put_image_to_window(game->mlx->mlx_connection, game->mlx->mlx_window,
		game->mlx->mlx_img_game_lost,
		(game->mlx->mlx_window_width - 200) / 2,
		(game->mlx->mlx_window_height - 200) / 2);
}

static void	sl_player_enter_field(t_sl_game *game, t_sl_point new_field)
{
	t_mlx_graphics	*mlx;

	mlx = game->mlx;
	if (new_field.symbol == SL_MAP_TOKEN)
	{
		sl_destroy_token(game, new_field);
		if (sl_unit_count(game->tokens) > 0)
			return ;
		game->exit_open = true;
		mlx_put_image_to_window(mlx->mlx_connection, mlx->mlx_window,
			mlx->mlx_img_exit_open, game->exit->pos->x * game->graphics_size,
			game->exit->pos->y * game->graphics_size);
	}
	if (new_field.symbol == SL_MAP_EXIT)
	{
		game->game_won = true;
		mlx_put_image_to_window(mlx->mlx_connection, mlx->mlx_window,
			mlx->mlx_img_game_won, (mlx->mlx_window_width - 200) / 2,
			(mlx->mlx_window_height - 200) / 2);
	}
	if (new_field.symbol == SL_MAP_PATROL)
		sl_player_dies(game);
}

static void	sl_player_move(t_sl_game *game, t_sl_point new_field)
{
	t_sl_point		old_field;
	t_mlx_graphics	*mlx;
	void			*new_img;

	mlx = game->mlx;
	sl_point_copy(&old_field, game->player->pos, 0, 0);
	game->map->fields[old_field.y][old_field.x] = SL_MAP_PATH;
	game->map->fields[new_field.y][new_field.x] = SL_MAP_PLAYER;
	game->player->pos->x = new_field.x;
	game->player->pos->y = new_field.y;
	game->moves++;
	mlx_put_image_to_window(mlx->mlx_connection, mlx->mlx_window,
		mlx->mlx_img_path, old_field.x * game->graphics_size,
		old_field.y * game->graphics_size);
	sl_player_enter_field(game, new_field);
	if (game->player_alive)
		new_img = mlx->mlx_img_player;
	else
		new_img = mlx->mlx_img_player_dead;
	mlx_put_image_to_window(mlx->mlx_connection, mlx->mlx_window,
		new_img, new_field.x * game->graphics_size,
		new_field.y * game->graphics_size);
	sl_print_moves(game);
}

void	sl_try_move_player(t_sl_game *game, int dx, int dy)
{
	t_sl_point	new_field;

	sl_point_copy(&new_field, game->player->pos, dx, dy);
	new_field.symbol = game->map->fields[new_field.y][new_field.x];
	if (new_field.symbol == SL_MAP_WALL || (new_field.symbol == SL_MAP_EXIT
			&& !game->exit_open))
		return ;
	sl_player_move(game, new_field);
}
