/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:42:54 by tkasbari          #+#    #+#             */
/*   Updated: 2023/12/04 11:46:11 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// the following 2 defines are necessary to access key-Macros in keysymdef.h
# ifndef XK_MISCELLANY
#  define XK_MISCELLANY
# endif

# ifndef XK_LATIN1
#  define XK_LATIN1
# endif

# include <X11/keysymdef.h>
# include <libft.h>
# include <sl_macros_bonus.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include <mlx.h>
# include <X11/X.h>

typedef struct s_sl_point
{
	int		x;
	int		y;
	char	symbol;
}			t_sl_point;

typedef struct s_sl_unit
{
	t_sl_point			*pos;
	bool				moveable;
	int					sprite_state;
	struct s_sl_unit	*next;
}			t_sl_unit;

typedef struct s_sl_map
{
	t_sl_point	*size;
	char		*map_str;
	char		**fields;

}			t_sl_map;

typedef struct s_mlx_graphics
{
	void	*mlx_connection;
	void	*mlx_window;
	int		mlx_window_width;
	int		mlx_window_height;
	void	*mlx_img_player;
	void	*mlx_img_patrol;
	void	*mlx_img_token_1;
	void	*mlx_img_token_2;
	void	*mlx_img_wall;
	void	*mlx_img_path;
	void	*mlx_img_exit_closed;
	void	*mlx_img_exit_open;
	void	*mlx_img_game_won;
	void	*mlx_img_game_lost;
	void	*mlx_img_player_dead;
	void	*mlx_img_moves;
	void	*mlx_img_digits[10];
}			t_mlx_graphics;

typedef struct s_sl_game
{
	t_sl_map		*map;
	t_sl_unit		*player;
	t_sl_unit		*tokens;
	t_sl_unit		*patrols;
	t_sl_unit		*exit;
	t_mlx_graphics	*mlx;
	int				graphics_size;
	int				moves;
	bool			exit_open;
	bool			player_alive;
	bool			game_aborted;
	bool			game_won;
	int				timer;
}				t_sl_game;

// so_long.c
void			sl_error_exit(t_sl_game *sl_game, char *err_msg);
void			sl_game_over(t_sl_game *sl_game);

// sl_map_read.c
void			sl_map_read(t_sl_game *game, char *map_file_path);

// sl_map_validate.c
void			sl_map_validate_dimensions(t_sl_game *game);
void			sl_map_validate_walls(t_sl_game *game);
bool			sl_map_search_path(char ***map, char *path_symbols,
					t_sl_point *start, t_sl_point *target);
bool			sl_map_point_reachable(t_sl_game *game,
					t_sl_point *start, t_sl_point *target);

// sl_create_structs.c
t_sl_point		*sl_create_point(t_sl_game *game, int p_x, int p_y,
					char p_symbol);
t_sl_unit		*sl_create_unit(t_sl_game *game, bool p_moveable,
					t_sl_point *p_point);
t_sl_map		*sl_create_map(t_sl_game *game);
t_sl_game		*sl_create_game(void);
t_mlx_graphics	*sl_create_graphics(t_sl_game *game);

// sl_init_structs.c
void			sl_init_point(t_sl_point *point);
void			sl_init_unit(t_sl_unit *unit);
void			sl_init_map(t_sl_map *map);
void			sl_init_graphics(t_sl_game *game, t_mlx_graphics *mlx);
void			sl_init_game(t_sl_game *game);

// sl_points.c
void			sl_point_copy(t_sl_point *dst, t_sl_point *src, int dx, int dy);

// sl_units.c
void			sl_units_parse_from_map(t_sl_game *game);
void			sl_units_validate(t_sl_game *game);
int				sl_unit_count(t_sl_unit *unit);
void			sl_destroy_unit(t_sl_unit *sl_unit);

// sl_init_graphics.c
void			sl_draw_game(t_sl_game *game);

// sl_sprites.c
int				sl_animate_sprites(t_sl_game *game);

// sl_mlx_events.c
void			sl_mlx_set_hooks(t_sl_game *game);

// sl_patrols.c
int				sl_move_patrols(t_sl_game *game);

// sl_player.c
void			sl_print_moves(t_sl_game *game);
void			sl_try_move_player(t_sl_game *game, int dx, int dy);
void			sl_player_dies(t_sl_game *game);

// sl_destroy.c
void			sl_destroy_token(t_sl_game *game, t_sl_point p_pos);
void			sl_destroy_game(t_sl_game *sl_game);

#endif
