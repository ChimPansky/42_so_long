/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_units_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:16:11 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/27 15:24:49 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_unit_count(t_sl_unit *unit)
{
	int			count;

	count = 0;
	while (unit)
	{
		count++;
		unit = unit->next;
	}
	return (count);
}

static void	sl_unit_add(t_sl_game *game, t_sl_unit *unit)
{
	t_sl_unit	**current;

	current = NULL;
	if (unit->pos->symbol == SL_MAP_PLAYER)
		current = &game->player;
	else if (unit->pos->symbol == SL_MAP_EXIT)
		current = &game->exit;
	else if (unit->pos->symbol == SL_MAP_TOKEN)
		current = &game->tokens;
	else if (unit->pos->symbol == SL_MAP_PATROL)
		current = &game->patrols;
	if (!current)
		return ;
	if (!*current)
	{
		*current = unit;
		return ;
	}
	while ((*current)->next)
		current = &(*current)->next;
	(*current)->next = unit;
}

void	sl_units_parse_from_map(t_sl_game *game)
{
	t_sl_point	pos;
	t_sl_point	*new_pos;
	t_sl_unit	*new_unit;

	pos.y = 1;
	while (pos.y < game->map->size->y - 1)
	{
		pos.x = 1;
		while (pos.x < game->map->size->x - 1)
		{
			pos.symbol = game->map->fields[pos.y][pos.x];
			if (!ft_strchr(SL_MAP_CHARSET, pos.symbol))
				sl_error_exit(game, ERR_MAP_CHARS);
			if (ft_strchr(SL_MAP_UNITS, pos.symbol))
			{
				new_pos = sl_create_point(game, pos.x, pos.y, pos.symbol);
				new_unit = sl_create_unit(game, false, new_pos);
				sl_unit_add(game, new_unit);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	sl_units_validate(t_sl_game *game)
{
	t_sl_unit	*token;

	if (sl_unit_count(game->player) < 1)
		sl_error_exit(game, ERR_MAP_NO_PLAYER);
	if (sl_unit_count(game->player) > 1)
		sl_error_exit(game, ERR_MAP_MULT_PLAYERS);
	if (sl_unit_count(game->exit) < 1)
		sl_error_exit(game, ERR_MAP_NO_EXIT);
	if (sl_unit_count(game->exit) > 1)
		sl_error_exit(game, ERR_MAP_MULT_EXITS);
	if (sl_unit_count(game->tokens) < 1)
		sl_error_exit(game, ERR_MAP_NO_TOKEN);
	token = game->tokens;
	while (token)
	{
		if (!sl_map_point_reachable(game, game->player->pos, token->pos))
			sl_error_exit(game, ERR_TOKEN_NOT_REACHABLE);
		token = token->next;
	}
	if (!sl_map_point_reachable(game, game->player->pos, game->exit->pos))
		sl_error_exit(game, ERR_EXIT_NOT_REACHABLE);
}

void	sl_destroy_unit(t_sl_unit *sl_unit)
{
	if (!sl_unit)
		return ;
	ft_free_and_null((void **)&sl_unit->pos);
	ft_free_and_null((void **)&sl_unit);
}
