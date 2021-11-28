/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:55:33 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/28 16:55:42 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	exit_game(t_game *game)
{
	(void) game;
	exit(0);
}

int	key_unpress(int key, t_game *game)
{
	if (key == KEY_W)
		game->flags.w_key = 0;
	if (key == KEY_S)
		game->flags.s_key = 0;
	if (key == KEY_A)
		game->flags.a_key = 0;
	if (key == KEY_D)
		game->flags.d_key = 0;
	if (key == KEY_LEFT)
		game->flags.left_key = 0;
	if (key == KEY_RIGHT)
		game->flags.right_key = 0;
	if (key == ESC)
		exit_game(game);
	else
		return (0);
	return (1);
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_W)
		game->flags.w_key = 1;
	if (key == KEY_S)
		game->flags.s_key = 1;
	if (key == KEY_A)
		game->flags.a_key = 1;
	if (key == KEY_D)
		game->flags.d_key = 1;
	if (key == KEY_LEFT)
		game->flags.left_key = 1;
	if (key == KEY_RIGHT)
		game->flags.right_key = 1;
	if (key == ESC)
		exit_game(game);
	else
		return (0);
	return (1);
}
