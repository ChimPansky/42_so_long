/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_graphics_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:59:54 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/28 14:20:00 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*sl_xpm_to_img(t_sl_game *game, char *img_path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx->mlx_connection, img_path,
			&width, &height);
	if (!img)
		sl_error_exit(game, img_path);
	return (img);
}

static void	sl_load_pictures_32(t_sl_game *game)
{
	game->mlx->mlx_img_player = sl_xpm_to_img(game, SL_PICS_PLAYER_32);
	game->mlx->mlx_img_patrol = sl_xpm_to_img(game, SL_PICS_PATROL_32);
	game->mlx->mlx_img_token_1 = sl_xpm_to_img(game, SL_PICS_TOKEN_1_32);
	game->mlx->mlx_img_token_2 = sl_xpm_to_img(game, SL_PICS_TOKEN_2_32);
	game->mlx->mlx_img_path = sl_xpm_to_img(game, SL_PICS_PATH_32);
	game->mlx->mlx_img_wall = sl_xpm_to_img(game, SL_PICS_WALL_32);
	game->mlx->mlx_img_exit_closed = sl_xpm_to_img(game,
			SL_PICS_EXIT_CLOSED_32);
	game->mlx->mlx_img_exit_open = sl_xpm_to_img(game, SL_PICS_EXIT_OPEN_32);
	game->mlx->mlx_img_player_dead = sl_xpm_to_img(game,
			SL_PICS_PLAYER_DEAD_32);
	game->mlx->mlx_img_game_won = sl_xpm_to_img(game, SL_PICS_GAME_WON);
	game->mlx->mlx_img_game_lost = sl_xpm_to_img(game, SL_PICS_GAME_LOST);
	game->mlx->mlx_img_moves = sl_xpm_to_img(game, SL_PICS_MOVES_32);
	game->mlx->mlx_img_digits[0] = sl_xpm_to_img(game, SL_PICS_DIGIT_16_0);
	game->mlx->mlx_img_digits[1] = sl_xpm_to_img(game, SL_PICS_DIGIT_16_1);
	game->mlx->mlx_img_digits[2] = sl_xpm_to_img(game, SL_PICS_DIGIT_16_2);
	game->mlx->mlx_img_digits[3] = sl_xpm_to_img(game, SL_PICS_DIGIT_16_3);
	game->mlx->mlx_img_digits[4] = sl_xpm_to_img(game, SL_PICS_DIGIT_16_4);
	game->mlx->mlx_img_digits[5] = sl_xpm_to_img(game, SL_PICS_DIGIT_16_5);
	game->mlx->mlx_img_digits[6] = sl_xpm_to_img(game, SL_PICS_DIGIT_16_6);
	game->mlx->mlx_img_digits[7] = sl_xpm_to_img(game, SL_PICS_DIGIT_16_7);
	game->mlx->mlx_img_digits[8] = sl_xpm_to_img(game, SL_PICS_DIGIT_16_8);
	game->mlx->mlx_img_digits[9] = sl_xpm_to_img(game, SL_PICS_DIGIT_16_9);
}

static void	sl_load_pictures_64(t_sl_game *game)
{
	game->mlx->mlx_img_player = sl_xpm_to_img(game, SL_PICS_PLAYER_64);
	game->mlx->mlx_img_patrol = sl_xpm_to_img(game, SL_PICS_PATROL_64);
	game->mlx->mlx_img_token_1 = sl_xpm_to_img(game, SL_PICS_TOKEN_1_64);
	game->mlx->mlx_img_token_2 = sl_xpm_to_img(game, SL_PICS_TOKEN_2_64);
	game->mlx->mlx_img_path = sl_xpm_to_img(game, SL_PICS_PATH_64);
	game->mlx->mlx_img_wall = sl_xpm_to_img(game, SL_PICS_WALL_64);
	game->mlx->mlx_img_exit_closed = sl_xpm_to_img(game,
			SL_PICS_EXIT_CLOSED_64);
	game->mlx->mlx_img_exit_open = sl_xpm_to_img(game, SL_PICS_EXIT_OPEN_64);
	game->mlx->mlx_img_player_dead = sl_xpm_to_img(game,
			SL_PICS_PLAYER_DEAD_64);
	game->mlx->mlx_img_game_won = sl_xpm_to_img(game, SL_PICS_GAME_WON);
	game->mlx->mlx_img_game_lost = sl_xpm_to_img(game, SL_PICS_GAME_LOST);
	game->mlx->mlx_img_moves = sl_xpm_to_img(game, SL_PICS_MOVES_64);
	game->mlx->mlx_img_digits[0] = sl_xpm_to_img(game, SL_PICS_DIGIT_32_0);
	game->mlx->mlx_img_digits[1] = sl_xpm_to_img(game, SL_PICS_DIGIT_32_1);
	game->mlx->mlx_img_digits[2] = sl_xpm_to_img(game, SL_PICS_DIGIT_32_2);
	game->mlx->mlx_img_digits[3] = sl_xpm_to_img(game, SL_PICS_DIGIT_32_3);
	game->mlx->mlx_img_digits[4] = sl_xpm_to_img(game, SL_PICS_DIGIT_32_4);
	game->mlx->mlx_img_digits[5] = sl_xpm_to_img(game, SL_PICS_DIGIT_32_5);
	game->mlx->mlx_img_digits[6] = sl_xpm_to_img(game, SL_PICS_DIGIT_32_6);
	game->mlx->mlx_img_digits[7] = sl_xpm_to_img(game, SL_PICS_DIGIT_32_7);
	game->mlx->mlx_img_digits[8] = sl_xpm_to_img(game, SL_PICS_DIGIT_32_8);
	game->mlx->mlx_img_digits[9] = sl_xpm_to_img(game, SL_PICS_DIGIT_32_9);
}

static void	*sl_get_img(t_sl_game *game, char symbol)
{
	void	*img;

	if (symbol == SL_MAP_PLAYER)
		img = game->mlx->mlx_img_player;
	else if (symbol == SL_MAP_PATROL)
		img = game->mlx->mlx_img_patrol;
	else if (symbol == SL_MAP_TOKEN)
		img = game->mlx->mlx_img_token_1;
	else if (symbol == SL_MAP_PATH)
		img = game->mlx->mlx_img_path;
	else if (symbol == SL_MAP_WALL)
		img = game->mlx->mlx_img_wall;
	else if (symbol == SL_MAP_EXIT)
		img = game->mlx->mlx_img_exit_closed;
	else
		img = game->mlx->mlx_img_path;
	if (!img)
		sl_error_exit(game, ERR_MLX_IMAGE_NOT_FOUND);
	return (img);
}

void	sl_draw_game(t_sl_game *gme)
{
	int	x;
	int	y;

	gme->mlx->mlx_window_width = (gme->map->size->x * gme->graphics_size);
	gme->mlx->mlx_window_height = (gme->map->size->y * gme->graphics_size);
	gme->mlx->mlx_window = mlx_new_window(gme->mlx->mlx_connection,
			gme->mlx->mlx_window_width, gme->mlx->mlx_window_height,
			SL_GAME_TITLE);
	if (!gme->mlx->mlx_window)
		sl_error_exit(gme, ERR_MLX_WINDOW);
	if (gme->graphics_size == 32)
		sl_load_pictures_32(gme);
	else
		sl_load_pictures_64(gme);
	x = 0;
	while (x < gme->map->size->y)
	{
		y = -1;
		while (++y < gme->map->size->x)
			mlx_put_image_to_window(gme->mlx->mlx_connection,
				gme->mlx->mlx_window, sl_get_img(gme, gme->map->fields[x][y]),
				gme->graphics_size * y, gme->graphics_size * x);
		x++;
	}
	sl_print_moves(gme);
}
