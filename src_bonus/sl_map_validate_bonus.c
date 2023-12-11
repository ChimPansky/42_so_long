/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_validate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:32:04 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/28 12:59:21 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_map_validate_dimensions(t_sl_game *game)
{
	int		i;
	char	*warn1;
	char	*warn2;

	warn1 = "The map you provided is very large.\n";
	warn2 = "For an optimal gaming experience a map size of maximum ";
	i = 0;
	if (game->map->size->x > SL_MAP_MAX_WIDTH
		|| game->map->size->y > SL_MAP_MAX_HEIGHT)
		ft_printf("%sWarning: %s%s%dx%d is recommended...%s\n", COLOR_YELLOW,
			warn1, warn2, SL_MAP_MAX_WIDTH, SL_MAP_MAX_HEIGHT, COLOR_RESET);
	if (game->map->size->x < 3 || game->map->size->y < 3)
		sl_error_exit(game, ERR_MAP_TOO_SMALL);
	while (game->map->fields[i])
	{
		if ((int)ft_strlen(game->map->fields[i++]) != game->map->size->x)
			sl_error_exit(game, ERR_MAP_NOT_RECTANGULAR);
	}
}

void	sl_map_validate_walls(t_sl_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->size->x)
	{
		if (game->map->fields[0][i] != SL_MAP_WALL
			|| game->map->fields[game->map->size->y - 1][i] != SL_MAP_WALL)
			sl_error_exit(game, ERR_MAP_WALLS);
		i++;
	}
	i = 0;
	while (i < game->map->size->y)
	{
		if (game->map->fields[i][0] != SL_MAP_WALL
			|| game->map->fields[i][game->map->size->x - 1] != SL_MAP_WALL)
			sl_error_exit(game, ERR_MAP_WALLS);
		i++;
	}
}

bool	sl_map_search_path(char ***map, char *path_symbols, t_sl_point *start,
	t_sl_point *target)
{
	t_sl_point	up;
	t_sl_point	left;
	t_sl_point	down;
	t_sl_point	right;

	if (!ft_strchr(path_symbols, start->symbol))
		return (false);
	if (start->x == target->x && start->y == target->y)
		return (true);
	(*map)[start->y][start->x] = '-';
	sl_point_copy(&up, start, 0, -1);
	sl_point_copy(&left, start, -1, 0);
	sl_point_copy(&down, start, 0, 1);
	sl_point_copy(&right, start, 1, 0);
	up.symbol = (*map)[up.y][up.x];
	left.symbol = (*map)[left.y][left.x];
	down.symbol = (*map)[down.y][down.x];
	right.symbol = (*map)[right.y][right.x];
	if (sl_map_search_path(map, path_symbols, &up, target)
		|| sl_map_search_path(map, path_symbols, &left, target)
		|| sl_map_search_path(map, path_symbols, &down, target)
		|| sl_map_search_path(map, path_symbols, &right, target))
		return (true);
	return (false);
}

bool	sl_map_point_reachable(t_sl_game *game,
		t_sl_point *start, t_sl_point *target)
{
	char		path_symbols[6];
	char		**map_copy;
	bool		result;
	t_sl_point	start_point;

	result = false;
	sl_point_copy(&start_point, start, 0, 0);
	if (start->x == target->x && start->y == target->y)
		return (true);
	if (!ft_strchr(SL_MAP_UNITS, target->symbol))
		return (false);
	ft_strlcpy(path_symbols, SL_MAP_PLAYER_WALKABLE, 6);
	if (target->symbol == SL_MAP_EXIT)
		path_symbols[4] = SL_MAP_EXIT;
	else
		path_symbols[4] = '\0';
	path_symbols[5] = '\0';
	map_copy = ft_split(game->map->map_str, '\n');
	if (!map_copy)
		sl_error_exit(game, ERR_MALLOC);
	result = sl_map_search_path(&map_copy, path_symbols, &start_point, target);
	ft_free_splitted(map_copy);
	return (result);
}
