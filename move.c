/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:31:05 by yenoh             #+#    #+#             */
/*   Updated: 2023/10/31 23:02:59 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_info *info)
{
	int	chk;

	if (info->map[info->y - 1][info->x] == '1')
		return ;
	else if (info->map[info->y - 1][info->x] == 'E')
	{
		if (info->c_cnt == 0)
			mlx_destroy_exit(info);
		else
			return ;
	}
	else if (info->map[info->y - 1][info->x] == 'C')
		info->c_cnt--;
	info->map[info->y][info->x] = '0';
	info->map[info->y - 1][info->x] = 'P';
	info->move_cnt++;
	info->y--;
	chk = ft_printd(info->move_cnt);
	if (chk == -1)
		perror_free_exit("print error", info);
}

void	move_left(t_info *info)
{
	int	chk;

	if (info->map[info->y][info->x - 1] == '1')
		return ;
	else if (info->map[info->y][info->x - 1] == 'E')
	{
		if (info->c_cnt == 0)
			mlx_destroy_exit(info);
		else
			return ;
	}
	else if (info->map[info->y][info->x - 1] == 'C')
		info->c_cnt--;
	info->map[info->y][info->x] = '0';
	info->map[info->y][info->x - 1] = 'P';
	info->move_cnt++;
	info->x--;
	chk = ft_printd(info->move_cnt);
	if (chk == -1)
		perror_free_exit("print error", info);
}

void	move_down(t_info *info)
{
	int	chk;

	if (info->map[info->y + 1][info->x] == '1')
		return ;
	else if (info->map[info->y + 1][info->x] == 'E')
	{
		if (info->c_cnt == 0)
			mlx_destroy_exit(info);
		else
			return ;
	}
	if (info->map[info->y + 1][info->x] == 'C')
		info->c_cnt--;
	info->map[info->y][info->x] = '0';
	info->map[info->y + 1][info->x] = 'P';
	info->move_cnt++;
	info->y++;
	chk = ft_printd(info->move_cnt);
	if (chk == -1)
		perror_free_exit("print error", info);
}

void	move_right(t_info *info)
{
	int	chk;

	if (info->map[info->y][info->x + 1] == '1')
		return ;
	else if (info->map[info->y][info->x + 1] == 'E')
	{
		if (info->c_cnt == 0)
			mlx_destroy_exit(info);
		else
			return ;
	}
	if (info->map[info->y][info->x + 1] == 'C')
		info->c_cnt--;
	info->map[info->y][info->x] = '0';
	info->map[info->y][info->x + 1] = 'P';
	info->move_cnt++;
	info->x++;
	chk = ft_printd(info->move_cnt);
	if (chk == -1)
		perror_free_exit("print error", info);
}

int	key_press(int key, t_info *info)
{
	if (key == KEY_W)
		move_up(info);
	else if (key == KEY_A)
		move_left(info);
	else if (key == KEY_S)
		move_down(info);
	else if (key == KEY_D)
		move_right(info);
	else if (key == KEY_ESC)
		mlx_destroy_exit(info);
	else
		return (0);
	draw_map(info);
	return (1);
}
