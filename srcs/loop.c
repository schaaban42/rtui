/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:15:01 by schaaban          #+#    #+#             */
/*   Updated: 2018/10/12 14:24:01 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

void				button_pressed(t_rt *rt)
{
	(void)rt;
	printf("Button pressed !\n");
}

void				sdl_loop(t_rt *rt)
{
	SDL_Surface		*screen_sf;
	t_btn			button;

	button = btn_new("button.bmp", (t_aabb){50, 50, 200, 100}, button_pressed);
	if (!(screen_sf = SDL_GetWindowSurface(rt->win)))
		return ; /* error */
	while (!rt->exit)
	{
		sdl_event_manager(rt);

		ft_update(rt);
		btn_update(rt, &button);

		ft_clear_screen(0xff000000, rt);

		btn_draw(rt, button);

		SDL_BlitSurface(rt->render, NULL, screen_sf, NULL);
		SDL_UpdateWindowSurface(rt->win);
	}
}
