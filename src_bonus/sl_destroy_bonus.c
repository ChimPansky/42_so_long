/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_destroy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:06:20 by tkasbari          #+#    #+#             */
/*   Updated: 2023/12/04 12:02:32 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_destroy_token(t_sl_game *game, t_sl_point p_pos)
{
	t_sl_unit	*prev;
	t_sl_unit	*cur;
	t_sl_unit	*next;

	if (!game->tokens)
		return ;
	prev = NULL;
	cur = game->tokens;
	while (cur)
	{
		next = cur->next;
		if (cur->pos->x == p_pos.x && cur->pos->y == p_pos.y)
			break ;
		prev = cur;
		cur = cur->next;
	}
	if (!prev)
		game->tokens = next;
	else
	{
		prev->next = next;
	}
	sl_destroy_unit(cur);
}

static void	sl_destroy_units(t_sl_unit *sl_unit)
{
	t_sl_unit	*cur_ptr;
	t_sl_unit	*next_ptr;

	if (!sl_unit)
		return ;
	cur_ptr = sl_unit;
	next_ptr = sl_unit->next;
	sl_destroy_unit(cur_ptr);
	while (next_ptr)
	{
		cur_ptr = next_ptr;
		next_ptr = cur_ptr->next;
		sl_destroy_unit(cur_ptr);
	}
}

static void	sl_destroy_mlx_image(void *mlx_connection, void *mlx_image)
{
	if (mlx_connection && mlx_image)
		mlx_destroy_image(mlx_connection, mlx_image);
}

static void	sl_destroy_graphics(t_mlx_graphics *mlx)
{
	int	i;

	i = -1;
	if (mlx && mlx->mlx_connection)
	{
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_player);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_patrol);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_token_1);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_token_2);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_wall);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_path);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_exit_closed);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_exit_open);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_game_won);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_game_lost);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_player_dead);
		sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_moves);
		while (++i < 10)
			sl_destroy_mlx_image(mlx->mlx_connection, mlx->mlx_img_digits[i]);
		if (mlx->mlx_window)
			mlx_destroy_window(mlx->mlx_connection, mlx->mlx_window);
		mlx_destroy_display(mlx->mlx_connection);
		ft_free_and_null((void **)&mlx->mlx_connection);
	}
	ft_free_and_null((void **)&mlx);
}

void	sl_destroy_game(t_sl_game *sl_game)
{
	if (!sl_game)
		return ;
	if (sl_game->map)
	{
		ft_free_splitted(sl_game->map->fields);
		ft_free_and_null((void **)&sl_game->map->map_str);
		ft_free_and_null((void **)&sl_game->map->size);
		ft_free_and_null((void **)&sl_game->map);
	}
	sl_destroy_units(sl_game->player);
	sl_destroy_units(sl_game->exit);
	sl_destroy_units(sl_game->tokens);
	sl_destroy_units(sl_game->patrols);
	sl_destroy_graphics(sl_game->mlx);
	ft_free_and_null((void **)&sl_game);
}
