/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:06:29 by schaaban          #+#    #+#             */
/*   Updated: 2018/12/10 05:20:44 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

static void			s_init_ptrs(t_rt *rt)
{
	int		i;

	i = -1;
	while (++i < 10)
		rt->digits[i] = NULL;
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
	rtui_init(&rt);
	sdl_loop(&rt);
	return (0);
}
