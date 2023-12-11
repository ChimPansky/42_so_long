/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_macros_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:04:58 by tkasbari          #+#    #+#             */
/*   Updated: 2023/12/04 10:54:27 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_MACROS_BONUS_H
# define SL_MACROS_BONUS_H

# define SL_GAME_TITLE "So Long Bonus"

# define SL_MAP_MAX_WIDTH 60
# define SL_MAP_MAX_HEIGHT 36

// Speed of Patrol movements and Token sprite animation (10...slow 100...fast)
# define SL_PATROL_SPEED 20
# define SL_SPRITE_SPEED 30

// Colors
# define COLOR_RESET "\033[0;39m"
# define COLOR_RED "\033[0;91m"
# define COLOR_GREEN "\033[0;92m"
# define COLOR_YELLOW "\033[0;93m"

# define SL_MAP_CHARSET "01CEPD"
# define SL_MAP_UNITS "CEPD"
# define SL_MAP_PLAYER_WALKABLE "0CPD"
# define SL_MAP_PATROL_WALKABLE "0P"
# define SL_MAP_PATH '0'
# define SL_MAP_WALL '1'
# define SL_MAP_TOKEN 'C'
# define SL_MAP_EXIT 'E'
# define SL_MAP_PLAYER 'P'
# define SL_MAP_PATROL 'D'

// General Error Messages:
# define SUCCESS 0
# define FAILURE 1
# define ERR_MALLOC "Memory Allocation Error"
# define ERR_UNKOWN "Unknown Error"

// Error Reading Map:
# define ERR_GNL "Could not read next line"
# define ERR_MAP_INVALID "Invalid Map"
# define ERR_TOO_FEW_PARAMETERS "No map parameter specified"
# define ERR_TOO_MANY_PARAMETERS "Too many parameters"
# define ERR_MAP_EXTENSION "Map must be a .ber File"

// Error Validating Map:
# define ERR_MAP_EMPTY_LINES "Map contains empty lines"
# define ERR_MAP_TOO_LARGE "Map too large"
# define ERR_MAP_TOO_SMALL "Map too small"
# define ERR_MAP_NOT_RECTANGULAR "Map not rectangular"
# define ERR_MAP_CHARS "Map consists of invalid character"
# define ERR_MAP_WALLS "Map not surrounded by walls"
# define ERR_MAP_NO_TOKEN "Map has no tokens"
# define ERR_MAP_NO_EXIT "Map has no exit"
# define ERR_MAP_MULT_EXITS "Map has more than one exit"
# define ERR_MAP_NO_PLAYER "Map has no player"
# define ERR_MAP_MULT_PLAYERS "Map has more than one player"
# define ERR_MAP_WRONG_EXIT "Map exit not reachable"
# define ERR_TOKEN_NOT_REACHABLE "Map consists of unreachable tokens"
# define ERR_EXIT_NOT_REACHABLE "Exit is unreachable"

// Error MLX (Graphics):
# define ERR_MLX_INIT "Could not establish connection to MLX server"
# define ERR_MLX_WINDOW "Could not create MLX window"
# define ERR_MLX_IMAGE "Could not create MLX image"
# define ERR_MLX_IMAGE_NOT_FOUND "Could not find image"

// Actions:
# define SL_ABORT '\e'
# define SL_MOVE_UP 'W'
# define SL_MOVE_LEFT 'A'
# define SL_MOVE_DOWN 'S'
# define SL_MOVE_RIGHT 'D'

// Pics
# define SL_PICS_GAME_WON "textures/xpm/game_won.xpm"
# define SL_PICS_GAME_LOST "textures/xpm/game_lost.xpm"

//	Pics and Sprites 64x64 pixels:
# define SL_PICS_PLAYER_64 "textures/xpm/player_64.xpm"
# define SL_PICS_TOKEN_1_64 "textures/xpm/token_1_64.xpm"
# define SL_PICS_TOKEN_2_64 "textures/xpm/token_2_64.xpm"
# define SL_PICS_PATROL_64 "textures/xpm/patrol_64.xpm"
# define SL_PICS_PATH_64 "textures/xpm/path_64.xpm"
# define SL_PICS_WALL_64 "textures/xpm/wall_64.xpm"
# define SL_PICS_EXIT_OPEN_64 "textures/xpm/exit_open_64.xpm"
# define SL_PICS_EXIT_CLOSED_64 "textures/xpm/exit_closed_64.xpm"
# define SL_PICS_PLAYER_DEAD_64 "textures/xpm/player_dead_64.xpm"
# define SL_PICS_MOVES_64 "textures/xpm/moves_64.xpm"

//	Pics and Sprites 32x32 pixels:
# define SL_PICS_PLAYER_32 "textures/xpm/player_32.xpm"
# define SL_PICS_TOKEN_1_32 "textures/xpm/token_1_32.xpm"
# define SL_PICS_TOKEN_2_32 "textures/xpm/token_2_32.xpm"
# define SL_PICS_PATROL_32 "textures/xpm/patrol_32.xpm"
# define SL_PICS_PATH_32 "textures/xpm/path_32.xpm"
# define SL_PICS_WALL_32 "textures/xpm/wall_32.xpm"
# define SL_PICS_EXIT_OPEN_32 "textures/xpm/exit_open_32.xpm"
# define SL_PICS_EXIT_CLOSED_32 "textures/xpm/exit_closed_32.xpm"
# define SL_PICS_PLAYER_DEAD_32 "textures/xpm/player_dead_32.xpm"
# define SL_PICS_MOVES_32 "textures/xpm/moves_32.xpm"

// Digits: 32x30 pixels:
# define SL_PICS_DIGIT_32_0 "textures/xpm/digit_32_0.xpm"
# define SL_PICS_DIGIT_32_1 "textures/xpm/digit_32_1.xpm"
# define SL_PICS_DIGIT_32_2 "textures/xpm/digit_32_2.xpm"
# define SL_PICS_DIGIT_32_3 "textures/xpm/digit_32_3.xpm"
# define SL_PICS_DIGIT_32_4 "textures/xpm/digit_32_4.xpm"
# define SL_PICS_DIGIT_32_5 "textures/xpm/digit_32_5.xpm"
# define SL_PICS_DIGIT_32_6 "textures/xpm/digit_32_6.xpm"
# define SL_PICS_DIGIT_32_7 "textures/xpm/digit_32_7.xpm"
# define SL_PICS_DIGIT_32_8 "textures/xpm/digit_32_8.xpm"
# define SL_PICS_DIGIT_32_9 "textures/xpm/digit_32_9.xpm"

// Digits: 16x15 pixels:
# define SL_PICS_DIGIT_16_0 "textures/xpm/digit_16_0.xpm"
# define SL_PICS_DIGIT_16_1 "textures/xpm/digit_16_1.xpm"
# define SL_PICS_DIGIT_16_2 "textures/xpm/digit_16_2.xpm"
# define SL_PICS_DIGIT_16_3 "textures/xpm/digit_16_3.xpm"
# define SL_PICS_DIGIT_16_4 "textures/xpm/digit_16_4.xpm"
# define SL_PICS_DIGIT_16_5 "textures/xpm/digit_16_5.xpm"
# define SL_PICS_DIGIT_16_6 "textures/xpm/digit_16_6.xpm"
# define SL_PICS_DIGIT_16_7 "textures/xpm/digit_16_7.xpm"
# define SL_PICS_DIGIT_16_8 "textures/xpm/digit_16_8.xpm"
# define SL_PICS_DIGIT_16_9 "textures/xpm/digit_16_9.xpm"

#endif
