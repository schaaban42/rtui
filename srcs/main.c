/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:06:29 by schaaban          #+#    #+#             */
/*   Updated: 2018/10/05 13:18:53 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

int					main(void)
{
	t_rt	rt;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (0);
	
	rt.win = SDL_CreateWindow("RT - UI",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	
	rt.render = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32,
		RT_SDL_RMASK, RT_SDL_GMASK, RT_SDL_BMASK, RT_SDL_AMASK);
	
	rt.exit = 0;

	sdl_loop(&rt);
	return (0);
}
