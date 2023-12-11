/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_create_structs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:25:34 by tkasbari          #+#    #+#             */
/*   Updated: 2023/12/04 11:44:36 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_point	*sl_create_point(t_sl_game *game, int p_x, int p_y, char p_symbol)
{
	t_sl_point	*new_point;

	if (!game)
		return (NULL);
	new_point = (t_sl_point *)(ft_calloc(sizeof(t_sl_point), 1));
	if (!new_point)
		sl_error_exit(game, ERR_MALLOC);
	sl_init_point(new_point);
	new_point->x = p_x;
	new_point->y = p_y;
	new_point->symbol = p_symbol;
	return (new_point);
}

t_sl_unit	*sl_create_unit(
	t_sl_game *game, bool p_moveable, t_sl_point *p_point)
{
	t_sl_unit	*new_unit;

	if (!game)
		return (NULL);
	new_unit = (t_sl_unit *)(ft_calloc(sizeof(t_sl_unit), 1));
	if (!new_unit)
	{
		ft_free_and_null((void **)&p_point);
		sl_error_exit(game, ERR_MALLOC);
	}
	sl_init_unit(new_unit);
	new_unit->moveable = p_moveable;
	if (p_point->symbol == SL_MAP_PLAYER)
		new_unit->moveable = true;
	new_unit->pos = p_point;
	new_unit->next = NULL;
	return (new_unit);
}

t_sl_map	*sl_create_map(t_sl_game *game)
{
	t_sl_map	*new_map;

	if (!game)
		return (NULL);
	new_map = (t_sl_map *)(ft_calloc(sizeof(t_sl_map), 1));
	if (!new_map)
		sl_error_exit(game, ERR_MALLOC);
	sl_init_map(new_map);
	return (new_map);
}

t_mlx_graphics	*sl_create_graphics(t_sl_game *game)
{
	t_mlx_graphics	*new_mlx;

	if (!game)
		return (NULL);
	new_mlx = (t_mlx_graphics *)(ft_calloc(sizeof(t_mlx_graphics), 1));
	if (!new_mlx)
		sl_error_exit(game, ERR_MALLOC);
	return (new_mlx);
}

t_sl_game	*sl_create_game(void)
{
	t_sl_game	*new_game;

	new_game = (t_sl_game *)(ft_calloc(sizeof(t_sl_game), 1));
	if (!new_game)
		sl_error_exit(NULL, ERR_MALLOC);
	sl_init_game(new_game);
	return (new_game);
}
