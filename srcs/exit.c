/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 00:27:13 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/13 13:03:10 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"
#include <unistd.h>

void				rt_exit(t_rt *rt)
{
	list_win_del(rt->list_win);
	list_btn_del(rt->gui.menu_main->list_btn);
	if (rt->gui.menu_main)
		ft_memdel((void**)&(rt->gui.menu_main));
	list_btn_del(rt->gui.menu_cam->list_btn);
	if (rt->gui.menu_cam)
		ft_memdel((void**)&(rt->gui.menu_cam));
	SDL_Quit();
	sleep(30);
	exit(0);
}
