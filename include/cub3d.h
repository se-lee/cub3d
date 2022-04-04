#ifndef	CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define TILE_SIZE			32
# define BUFFER_SIZE		1

/* KEYS */
# define KEY_ESC			53
# define KEY_SPACE			49
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124

# define EVENT_KEY_PRESS	2
# define EVENT_EXIT			17

/* DIRECTION */
# define DIR_NO				1
# define DIR_SO				2
# define DIR_WE				3
# define DIR_EA				4

/* GAME STATUS */
# define GAME_START			1
# define GAME_PLAY			2
# define GAME_CONTINUE		3
# define GAME_END			4


typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		height;
	int		width;
} t_image;

typedef struct s_texture
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor[3];
	int		ceiling[3];
}	t_texture;

typedef struct s_map
{
	char		**array;
	int			row_count;
	int			column_count;
	t_texture	texture;
} t_map;

typedef struct s_tile
{
	t_image	wall;
	t_image	space;
}	t_tile;

/*
structure for raycaster?
distance
height...

*/

typedef struct s_player
{
	int			x;
	int			y;
	int			x_start;
	int			y_start;
	t_image		image;
}	t_player;


typedef struct s_cub
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
	t_tile		tile;

	int			status;
} t_cub;

/* init */
void	init_game();
void	init_game_img();
void	init_mlx_and_window();
void	init_map_value();


/* get_next_line */
int	get_next_line(int fd, char **line);

/* display */
void	put_map_to_win(t_cub *cub);

/* error */
void	error_message_exit(char *message);

/* exit */
int	exit_hook(void);

/* free */
void	free_map_arr(t_cub *cub);

/* map */
int	map_check_file_extension(char *filename, char *ext);
void	map_read_and_check(t_cub *cub, char *map_path);
void	map_check_format(t_cub *cub);

/* event */
int		key_input(int keycode, t_cub *cub);
void	move_to_directions(t_cub *cub, int direction);
int		player_touched_wall(t_cub *cub, int direction);

void	player_get_coord(t_cub *cub);

#endif