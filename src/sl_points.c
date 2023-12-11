/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_points_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:24:51 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/24 18:31:32 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_point_copy(t_sl_point *dst, t_sl_point *src, int dx, int dy)
{
	if (!src || !dst)
		return ;
	dst->x = src->x + dx;
	dst->y = src->y + dy;
	dst->symbol = src->symbol;
}
