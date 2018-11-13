/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:06:29 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/11 07:08:31 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

static void			s_init_ptrs(t_rt *rt)
{
	rt->win = NULL;
	rt->render = NULL;
	rt->list_win = NULL;
	rt->focus_win = NULL;
	rt->mouse_win = NULL;
	rt->gui.menu_main = NULL;
	rt->gui.menu_cam = NULL;
}

int					main(void)
{
	t_rt	rt;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (0);
	s_init_ptrs(&rt);

	if (!(rt.gui.menu_main = (t_menu*)ft_memalloc(sizeof(t_menu))))
		error_handler(&rt, ERR_MALLOC);
	rt.gui.menu_main->list_btn = NULL;
	rt.gui.menu_main->cam_y = 0;

	if (!(rt.gui.menu_cam = (t_menu*)ft_memalloc(sizeof(t_menu))))
		error_handler(&rt, ERR_MALLOC);
	rt.gui.menu_cam->list_btn = NULL;
	rt.gui.menu_cam->cam_y = 0;

	list_win_add(&rt, &(rt.list_win), (t_list_win){0,
		SDL_CreateWindow("RT - UI", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, UI_WIDTH, UI_HEIGHT, 0), NULL, NULL});
	rt.id_main_win = SDL_GetWindowID(rt.list_win->win);
	rt.exit = 0;

	sdl_loop(&rt);
	return (0);
}
