/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:16:05 by schaaban          #+#    #+#             */
/*   Updated: 2018/10/10 15:22:03 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

static Uint32		s_get_rgba(Uint32 base_color, t_rt *rt)
{
	return (SDL_MapRGBA(rt->render->format,
		(base_color & 0xff0000) >> 16,
		(base_color & 0xff00) >> 8,
		(base_color & 0xff),
		(base_color & 0xff000000) >> 24));
}

void				ft_put_pixel(int x, int y, Uint32 c, t_rt *rt)
{
    Uint8 *p;

	c = s_get_rgba(c, rt);
	p = (Uint8*)rt->render->pixels + y * rt->render->pitch
		+ x * rt->render->format->BytesPerPixel;
    *(Uint32*)p = c;
	if (rt->render->format->BytesPerPixel == 1)
		*p = c;
	else if (rt->render->format->BytesPerPixel == 2)
		*(Uint16*)p = c;
	else if (rt->render->format->BytesPerPixel == 3)
	{
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (c >> 16) & 0xff;
			p[1] = (c >> 8) & 0xff;
			p[2] = c & 0xff;
		}
		else
		{
			p[0] = c & 0xff;
			p[1] = (c >> 8) & 0xff;
			p[2] = (c >> 16) & 0xff;
		}
	}
}

void				ft_clear_screen(Uint32 color, t_rt *rt)
{
	int		i;
	int		j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			ft_put_pixel(j, i, color, rt);
	}
}
