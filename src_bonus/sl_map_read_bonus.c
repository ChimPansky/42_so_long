/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_read_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:16:50 by tkasbari          #+#    #+#             */
/*   Updated: 2023/12/04 12:02:50 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	sl_map_set_size(t_sl_game *game)
{
	if (!game || !game->map || !game->map->fields)
		return ;
	if (!game->map->size)
		game->map->size = sl_create_point(game, 0, 0, 0);
	game->map->size->x = 0;
	game->map->size->y = 0;
	while (game->map->fields[game->map->size->y])
		game->map->size->y++;
	if (!game->map->size->y)
		return ;
	game->map->size->x = ft_strlen(game->map->fields[0]);
	if (game->map->size->x > 18 || game->map->size->y > 30)
		game->graphics_size = 32;
	else
		game->graphics_size = 64;
}

static void	sl_map_gnl(t_sl_game *game, int map_fd)
{
	t_line	line;

	line = get_next_line(map_fd);
	if (line.error)
		sl_error_exit(game, ERR_GNL);
	while (line.str)
	{
		if (*line.str == '\n')
		{
			free(line.str);
			sl_error_exit(game, ERR_MAP_EMPTY_LINES);
		}
		game->map->map_str = ft_strjoin_free(game->map->map_str,
				line.str, true, true);
		if (!game->map->map_str)
			sl_error_exit(game, ERR_MALLOC);
		line = get_next_line(map_fd);
		if (line.error)
			sl_error_exit(game, ERR_GNL);
	}
}

void	sl_map_read(t_sl_game *game, char *map_file_path)
{
	int		map_fd;

	if (ft_file_check_extension(map_file_path, "ber"))
		sl_error_exit(game, ERR_MAP_EXTENSION);
	map_fd = open(map_file_path, O_RDONLY);
	if (map_fd < 0)
		sl_error_exit(game, map_file_path);
	game->map->map_str = ft_strdup("");
	if (!game->map->map_str)
		sl_error_exit(game, ERR_MALLOC);
	sl_map_gnl(game, map_fd);
	if (close(map_fd) == -1)
		sl_error_exit(game, "Map File descriptor");
	game->map->fields = ft_split(game->map->map_str, '\n');
	if (!game->map->fields)
		sl_error_exit(game, ERR_MALLOC);
	sl_map_set_size(game);
}
