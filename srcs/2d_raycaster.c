#include "cub3d.h"

void	draw_line(t_cub *cub, int x, int y1, int y2, int color)
{
	int		y;
	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(cub->mlx, cub->win, x, y, color);
		y++;
	}
}
