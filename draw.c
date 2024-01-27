
#include "cub3D.h"

void	drawall(t_all *all, int **buffer)
{
	int	i;
	int	j;
	int	*texture;

	i = 0;
	j = 0;
	all->mlx->img = mlx_new_image(all->mlx->mlx,WinWidth, WinHeight);
	texture = (int *)mlx_get_data_addr(all->mlx->img, &all->mlx->b,
			&all->mlx->w, &all->mlx->h);
	while (j < WinHeight)
	{
		i = 0;
		while (i < WinWidth)
		{
			texture[j * WinWidth + i] = buffer[j][i];
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(all->mlx->mlx,
		all->mlx->mlx_win, all->mlx->img, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
}

void	fill_ceil(t_all *all, int y, int x)
{
	while (y < WinHeight)
	{
		if (all->mlx->drawend < 0 || all->mlx->drawend < all->mlx->drawstart)
			break ;
		all->mlx->buffer[y][x] = all->mlx->fcolor;
		y++;
	}
}

void	get_floor_ceil(t_all *all, int y, int x)
{
	while (y < all->mlx->drawstart)
	{
		if (all->mlx->drawstart < 0 || all->mlx->drawstart > all->mlx->drawend)
			break ;
		all->mlx->buffer[y][x] = all->mlx->ccolor;
		y++;
	}
	y = all->mlx->drawend;
	fill_ceil(all, y, x);
	y = 0;
	while (y < WinHeight)
	{
		if (all->mlx->buffer[y][x] == 0 && all->ray->updown > 0 && \
		(y < all->mlx->drawstart || y > all->mlx->drawend))
			all->mlx->buffer[y][x] = all->mlx->ccolor;
		if (all->mlx->buffer[y][x] == 0 && all->ray->updown < 0 && \
		(y < all->mlx->drawstart || y > all->mlx->drawend))
			all->mlx->buffer[y][x] = all->mlx->fcolor;
		y++;
	}
}

void	gettexture(t_all *all, int ii)
{
	if (ii == 1)
		all->ray->color = mlx_get_color_value(all->mlx->mlx, all->mlx->text
			[(64 * all->mlx->texy) + all->mlx->texx]);
	else if (ii == 2)
		all->ray->color = mlx_get_color_value(all->mlx->mlx, all->mlx
				->text2[(64 * all->mlx->texy) + all->mlx->texx]);
	else if (ii == 3)
		all->ray->color = mlx_get_color_value(all->mlx->mlx, all->mlx
				->text3[(64 * all->mlx->texy) + all->mlx->texx]);
	else if (ii == 4)
		all->ray->color = mlx_get_color_value(all->mlx->mlx, all->mlx
				->text4[(64 * all->mlx->texy) + all->mlx->texx]);
}

void	player_pos(t_all *all, char **map, int *ii)
{
	extracheck(all);
	if (all->mlx->drawend >= WinHeight)
		all->mlx->drawend = WinHeight - 1;
	if (all->ray->side == 0 && map[(int)all->ray->mapx]
		[(int)all->ray->mapy] == '1')
	{
		all->ray->wallx = all->pl->posy + all
			->ray->perpwalldist * all->ray->raydiry;
		if (all->ray->raydirx > 0)
			*ii = 2;
		else
			*ii = 1;
	}
	else
	{
		all->ray->wallx = all->pl->posx + all
			->ray->perpwalldist * all->ray->raydirx;
		if (all->ray->raydiry > 0)
			*ii = 3;
		else
			*ii = 4;
	}
}
