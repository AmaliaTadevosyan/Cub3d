/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:20:10 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/19 12:20:14 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_addres *address, double rotate)
{
	double	old_pos;

	old_pos = address->rcasting->dirx;
	address->rcasting->dirx = old_pos * cos(rotate) - \
	address->rcasting->diry * sin(rotate);
	address->rcasting->diry = old_pos * sin(rotate) + \
	address->rcasting->diry * cos(rotate);
	old_pos = address->rcasting->planex;
	address->rcasting->planex = old_pos * cos(rotate) - \
	address->rcasting->planey * sin(rotate);
	address->rcasting->planey = old_pos * sin(rotate) + \
	address->rcasting->planey * cos(rotate);
}

void	move_left(t_addres *address)
{
	int	x;
	int	y;

	x = (int)(address->rcasting->posx - address->rcasting->planex * \
	(MOVE_SPEED + 0.1));
	y = (int)address->rcasting->posy;
	if (address->cub->map[x][y] == '0')
		address->rcasting->posx -= address->rcasting->planex * MOVE_SPEED;
	x = (int)address->rcasting->posx;
	y = (int)(address->rcasting->posy - address->rcasting->planey * \
	(MOVE_SPEED + 0.1));
	if (address->cub->map[x][y] == '0')
		address->rcasting->posy -= address->rcasting->planey * MOVE_SPEED;
}

void	move_right(t_addres *address)
{
	int	x;
	int	y;

	x = (int)(address->rcasting->posx + address->rcasting->planex * \
	(MOVE_SPEED + 0.1));
	y = (int)address->rcasting->posy;
	if (address->cub->map[x][y] == '0')
		address->rcasting->posx += address->rcasting->planex * MOVE_SPEED;
	x = (int)address->rcasting->posx;
	y = (int)(address->rcasting->posy + address->rcasting->planey * \
	(MOVE_SPEED + 0.1));
	if (address->cub->map[x][y] == '0')
		address->rcasting->posy += address->rcasting->planey * MOVE_SPEED;
}

void	move_up(t_addres *address)
{
	int	x;
	int	y;

	x = (int)(address->rcasting->posx + \
	address->rcasting->dirx * (MOVE_SPEED + 0.1));
	y = (int)address->rcasting->posy;
	if (address->cub->map[x][y] == '0')
		address->rcasting->posx += address->rcasting->dirx * MOVE_SPEED;
	x = (int)address->rcasting->posx;
	y = (int)(address->rcasting->posy + \
	address->rcasting->diry * (MOVE_SPEED + 0.1));
	if (address->cub->map[x][y] == '0')
		address->rcasting->posy += address->rcasting->diry * MOVE_SPEED;
}

void	move_down(t_addres *address)
{
	int	x;
	int	y;

	x = (int)(address->rcasting->posx - \
	address->rcasting->dirx * (MOVE_SPEED + 0.1));
	y = (int)address->rcasting->posy;
	if (address->cub->map[x][y] == '0')
		address->rcasting->posx -= address->rcasting->dirx * MOVE_SPEED;
	x = (int)address->rcasting->posx;
	y = (int)(address->rcasting->posy - \
	address->rcasting->diry * (MOVE_SPEED + 0.1));
	if (address->cub->map[x][y] == '0')
		address->rcasting->posy -= address->rcasting->diry * MOVE_SPEED;
}
