/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:19:24 by schaaban          #+#    #+#             */
/*   Updated: 2018/10/10 15:21:41 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

static void			s_event_window(t_rt *rt)
{
	if (rt->event.type == SDL_WINDOWEVENT)
	{
		if (rt->event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			rt->exit = 1;
		}
	}
	if (rt->event.type == SDL_QUIT)
	{
		rt->exit = 1;
	}
}

static void			s_event_keys(t_rt *rt)
{
	if (rt->event.key.keysym.sym == SDLK_ESCAPE)
	{
		rt->exit = 1;
	}
	if (rt->event.key.keysym.sym == SDLK_r)
	{
		ft_clear_screen(0xff3333ff, rt);
	}
	if (rt->event.key.keysym.sym == SDLK_e)
	{
		rt_export_screenshoot(rt, "file.bmp");
	}
}

void				sdl_event_manager(t_rt *rt)
{
	while (SDL_PollEvent(&rt->event))
	{
		s_event_window(rt);
		if (rt->event.type == SDL_KEYDOWN)
			s_event_keys(rt);
	}
	return ;
}