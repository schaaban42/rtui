/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 00:27:13 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/11 07:07:32 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

static void			s_free_sdl(t_rt *rt)
{
	if (rt->win)
		SDL_DestroyWindow(rt->win);
}

void				rt_exit(t_rt *rt)
{
	s_free_sdl(rt);
	list_win_del(rt->list_win);
	list_btn_del(rt->gui.menu_main->list_btn);
	if (rt->gui.menu_main)
		ft_memdel((void**)&(rt->gui.menu_main));
	list_btn_del(rt->gui.menu_cam->list_btn);
	if (rt->gui.menu_cam)
		ft_memdel((void**)&(rt->gui.menu_cam));
	SDL_Quit();
	exit(0);
}
