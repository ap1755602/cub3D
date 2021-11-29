/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:49:23 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/29 12:49:48 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "rendering.h"

int	main(int argc, char*argv[])
{
	t_game	game;

	if (argc == 2)
	{
		game.map = parse(argv[1]);
		start_game(&game);
		return (0);
	}
	terminate("Error");
}
