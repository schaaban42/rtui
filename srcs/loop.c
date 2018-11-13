/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:15:01 by schaaban          #+#    #+#             */
/*   Updated: 2018/11/11 20:48:16 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

void				menu_cam(t_rt *rt)
{
	rt->gui.actual_menu = rt->gui.menu_cam;
}

void				menu_main(t_rt *rt)
{
	rt->gui.actual_menu = rt->gui.menu_main;
}

void				open_new_win(t_rt *rt)
{
	list_win_add(rt, &(rt->list_win), (t_list_win){0,
		SDL_CreateWindow("Camera", 0, 0, 600, 350, 0), NULL, NULL});
	ft_clear_screen(0xffff0000, rt->list_win);
}

void				sdl_loop(t_rt *rt)
{
	t_list_win	*it_list_win;

	list_btn_add(rt, &(rt->gui.menu_main->list_btn), (t_list_btn){
		sdl_img_import("img/btn_exit.bmp"),
		sdl_img_import("img/btn_exit_h.bmp"),
		sdl_img_import("img/btn_exit_c.bmp"), (t_aabb){0, 0, 0, 0},
		0, 0, &rt_exit, NULL});
	list_btn_add(rt, &(rt->gui.menu_main->list_btn), (t_list_btn){
		sdl_img_import("img/btn_cam.bmp"),
		sdl_img_import("img/btn_cam_h.bmp"),
		sdl_img_import("img/btn_cam_c.bmp"), (t_aabb){0, 0, 0, 0},
		0, 0, &menu_cam, NULL});

	list_btn_add(rt, &(rt->gui.menu_cam->list_btn), (t_list_btn){
		sdl_img_import("img/btn_cam.bmp"),
		sdl_img_import("img/btn_cam_h.bmp"),
		sdl_img_import("img/btn_cam_c.bmp"), (t_aabb){0, 0, 0, 0},
		0, 0, &open_new_win, NULL});
	list_btn_add(rt, &(rt->gui.menu_cam->list_btn), (t_list_btn){
		sdl_img_import("img/btn_cam.bmp"),
		sdl_img_import("img/btn_cam_h.bmp"),
		sdl_img_import("img/btn_cam_c.bmp"), (t_aabb){0, 0, 0, 0},
		0, 0, &open_new_win, NULL});
	list_btn_add(rt, &(rt->gui.menu_cam->list_btn), (t_list_btn){
		sdl_img_import("img/btn_cam.bmp"),
		sdl_img_import("img/btn_cam_h.bmp"),
		sdl_img_import("img/btn_cam_c.bmp"), (t_aabb){0, 0, 0, 0},
		0, 0, &open_new_win, NULL});
	list_btn_add(rt, &(rt->gui.menu_cam->list_btn), (t_list_btn){
		sdl_img_import("img/btn_cam.bmp"),
		sdl_img_import("img/btn_cam_h.bmp"),
		sdl_img_import("img/btn_cam_c.bmp"), (t_aabb){0, 0, 0, 0},
		0, 0, &open_new_win, NULL});
	list_btn_add(rt, &(rt->gui.menu_cam->list_btn), (t_list_btn){
		sdl_img_import("img/btn_cam.bmp"),
		sdl_img_import("img/btn_cam_h.bmp"),
		sdl_img_import("img/btn_cam_c.bmp"), (t_aabb){0, 0, 0, 0},
		0, 0, &open_new_win, NULL});
	list_btn_add(rt, &(rt->gui.menu_cam->list_btn), (t_list_btn){
		sdl_img_import("img/btn_cam.bmp"),
		sdl_img_import("img/btn_cam_h.bmp"),
		sdl_img_import("img/btn_cam_c.bmp"), (t_aabb){0, 0, 0, 0},
		0, 0, &open_new_win, NULL});
	list_btn_add(rt, &(rt->gui.menu_cam->list_btn), (t_list_btn){
		sdl_img_import("img/btn_back.bmp"),
		sdl_img_import("img/btn_back_h.bmp"),
		sdl_img_import("img/btn_back_c.bmp"), (t_aabb){0, 0, 0, 0},
		0, 0, &menu_main, NULL});

	rt->gui.actual_menu = rt->gui.menu_main;

	gui_set_button_pos(rt->gui.menu_main);
	gui_set_button_pos(rt->gui.menu_cam);
	while (!rt->exit)
	{
		sdl_event_manager(rt);

		ft_update(rt);

		list_btn_cam(rt, 1);
		if (rt->mouse_win)
		{
			if (rt->mouse_win->id == rt->id_main_win)
				list_btn_update(rt, rt->gui.actual_menu->list_btn, 0);
		}
		else
			list_btn_update(rt, rt->gui.actual_menu->list_btn, 1);

		ft_clear_screen(0xffffff00,
			list_win_get(rt->list_win, rt->id_main_win));
		list_btn_draw(list_win_get(rt->list_win, rt->id_main_win),
			rt->gui.actual_menu->list_btn);
		list_btn_cam(rt, 0);

		it_list_win = rt->list_win;
		while (it_list_win)
		{
			SDL_UpdateWindowSurface(it_list_win->win);
			it_list_win = it_list_win->next;
		}
	}
	rt_exit(rt);
}
