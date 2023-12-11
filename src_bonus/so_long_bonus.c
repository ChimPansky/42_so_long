/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:13:33 by tkasbari          #+#    #+#             */
/*   Updated: 2023/12/04 11:19:46 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_error_exit(t_sl_game *sl_game, char *err_msg)
{
	ft_putstr_fd(COLOR_RED, STDERR_FILENO);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno)
		perror(err_msg);
	else
		ft_putendl_fd(err_msg, STDERR_FILENO);
	ft_putstr_fd(COLOR_RESET, STDERR_FILENO);
	sl_destroy_game(sl_game);
	if (errno)
		exit(errno);
	else
		exit(1);
}

void	sl_game_over(t_sl_game *sl_game)
{
	if (!sl_game->game_won && sl_game->player_alive && !sl_game->game_aborted)
		return ;
	if (sl_game->game_won)
	{
		ft_putstr_fd("You won!\nMoves to complete the game: ", STDOUT_FILENO);
		ft_putnbr_fd(sl_game->moves, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else if (!sl_game->player_alive)
		ft_putstr_fd("You lost! Better luck next time!\n", STDOUT_FILENO);
	else if (sl_game->game_aborted)
		ft_putstr_fd("Game aborted!\n", STDOUT_FILENO);
	sl_destroy_game(sl_game);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_sl_game	*sl_game;

	ft_putstr_fd("Loading Game... Please Wait.\n", STDOUT_FILENO);
	sl_game = sl_create_game();
	sl_game->map = sl_create_map(sl_game);
	if (argc < 2)
		sl_error_exit(sl_game, ERR_TOO_FEW_PARAMETERS);
	if (argc > 2)
		sl_error_exit(sl_game, ERR_TOO_MANY_PARAMETERS);
	sl_map_read(sl_game, argv[1]);
	sl_map_validate_dimensions(sl_game);
	sl_map_validate_walls(sl_game);
	sl_units_parse_from_map(sl_game);
	sl_units_validate(sl_game);
	sl_game->mlx = sl_create_graphics(sl_game);
	sl_init_graphics(sl_game, sl_game->mlx);
	sl_draw_game(sl_game);
	srand(time(NULL));
	sl_mlx_set_hooks(sl_game);
	ft_putstr_fd("Game ready.\n", STDOUT_FILENO);
	mlx_loop(sl_game->mlx->mlx_connection);
	sl_destroy_game(sl_game);
	return (0);
}
