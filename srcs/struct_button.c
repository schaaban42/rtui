/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:49:13 by schaaban          #+#    #+#             */
/*   Updated: 2018/10/11 18:31:12 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

t_btn				btn_new(char *filename, t_aabb aabb,
	void (*action_call)(t_rt*))
{
	t_btn		button = (t_btn)
	{
		sdl_img_import(filename),
		aabb,
		0, 0,
		action_call
	};

	return (button);
}

void				btn_update(t_rt *rt, t_btn *button)
{
	t_v2	mouse_v2;
	int		mx;
	int		my;

	SDL_GetMouseState(&mx, &my);
	mouse_v2 = (t_v2){mx, my, 0};
	if (aabb_col_pt(button->aabb, mouse_v2))
	{
		button->st_hover = 1;
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
			button->st_pressing = 1;
		else
		{
			if (button->st_pressing)
			{
				button->st_pressing = 0;
				(button->action_call)(rt);
			}
		}
	}
	else
	{
		if (!(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)))
			button->st_pressing = 0;
		button->st_hover = 0;
	}
}

void				btn_draw(t_rt *rt, t_btn btn)
{
	SDL_Rect	dst;

	dst = (SDL_Rect)
	{
		btn.aabb.x,
		btn.aabb.y,
		btn.aabb.w,
		btn.aabb.h
	};
	SDL_BlitSurface(btn.tex, NULL, rt->render, &dst);
	if (btn.st_hover)
		SDL_FillRect(rt->render, &dst, 0x11ff0000);
	if (btn.st_pressing)
		SDL_FillRect(rt->render, &dst, 0xff0000ff);
}
