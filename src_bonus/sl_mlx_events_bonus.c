/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:51:03 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/27 16:03:40 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	sl_key_press(int keysym, t_sl_game *game)
{
	if (!game->game_won && game->player_alive)
	{
		if (keysym == XK_w || keysym == XK_Up)
			sl_try_move_player(game, 0, -1);
		else if (keysym == XK_a || keysym == XK_Left)
			sl_try_move_player(game, -1, 0);
		else if (keysym == XK_s || keysym == XK_Down)
			sl_try_move_player(game, 0, 1);
		else if (keysym == XK_d || keysym == XK_Right)
			sl_try_move_player(game, 1, 0);
	}
	return (SUCCESS);
}

static int	sl_key_release(int key, t_sl_game *game)
{
	if ((game->game_won || !game->player_alive) && (key == XK_Escape
			|| key == XK_Return || key == XK_q || key == XK_q))
		sl_game_over(game);
	else if (key == XK_Escape)
	{
		game->game_aborted = true;
		sl_game_over(game);
	}
	return (SUCCESS);
}

static int	sl_loop_event(t_sl_game *game)
{
	game->timer++;
	if (game->game_won || !game->player_alive)
		return (FAILURE);
	if (SL_PATROL_SPEED && game->timer % (1000000 / SL_PATROL_SPEED) == 0)
		sl_move_patrols(game);
	if (SL_SPRITE_SPEED && game->timer % (1000000 / SL_SPRITE_SPEED) == 0)
		sl_animate_sprites(game);
	return (SUCCESS);
}

static int	sl_destroy_notify(t_sl_game *game)
{
	game->game_aborted = true;
	sl_game_over(game);
	return (SUCCESS);
}

void	sl_mlx_set_hooks(t_sl_game *game)
{
	void	*mlx_conn;
	void	*mlx_window;

	mlx_conn = game->mlx->mlx_connection;
	mlx_window = game->mlx->mlx_window;
	mlx_hook(mlx_window, DestroyNotify, StructureNotifyMask,
		sl_destroy_notify, game);
	mlx_hook(mlx_window, KeyPress, KeyPressMask, sl_key_press, game);
	mlx_hook(mlx_window, KeyRelease, KeyReleaseMask, sl_key_release, game);
	mlx_loop_hook(mlx_conn, sl_loop_event, game);
}
