/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_sprites_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:10:32 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/27 16:02:09 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_animate_sprites(t_sl_game *game)
{
	t_sl_unit	*unit;
	void		*img;

	unit = game->tokens;
	while (unit)
	{
		if (unit->sprite_state == 1)
		{
			img = game->mlx->mlx_img_token_2;
			unit->sprite_state = 2;
		}
		else
		{
			img = game->mlx->mlx_img_token_1;
			unit->sprite_state = 1;
		}
		mlx_put_image_to_window(game->mlx->mlx_connection,
			game->mlx->mlx_window, img,
			unit->pos->x * game->graphics_size,
			unit->pos->y * game->graphics_size);
		unit = unit->next;
	}
	return (SUCCESS);
}
